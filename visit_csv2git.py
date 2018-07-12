"""
This is a specialized script to migrate VisIt issues from redmine to 
github issues. 

@author: Alister Maguire
@date: Tue Jun 26 13:15:22 PDT 2018

Acknowledgements:
    https://gist.github.com/nqthqn/9abcefb8a29e3292b3ca42026f0da23f
    (for a great starter script)
"""
import json
import glob
import os
import requests
import csv
from time import sleep
import random
import argparse
from authentication import *

#TODO: create a limit checker?
#      once limit is about to be exceeded, wait. 


SHORT_WAIT    = 3
MAX_ATTEMPTS  = 5
LONG_WAIT     = 3700
BLOCK_FLAGS   = ["temporarily blocked from content", "API rate limit exceeded"]


def exceeded_limit(response):
    """
        Check an API response from github to determine if we've 
        exceeded our communication limit. 
    """
    for flag in BLOCK_FLAGS:
        if flag in response.content: 
            return True
    return False


def invalid_assignee(response):
    """
        Determine if an API response notifies us that our
        assignee is invalid. 
    """
    errors = json.loads(response.content)["errors"]
    field  = errors[0]["field"]
    code   = errors[0]["code"]
    if "assignees" in field and "invalid" in code:
        return True
    return False


def create_redmine_tag(row, comment_map):
    """
        Create a tag which contains all information from the
        original redmine ticket. 
        Note: attachments can't be added through the git API, 
        so they are not included in this. 
    """
    template = ("\n\n\n\n"
         "-----------------------REDMINE MIGRATION-----------------------\n"
         "This ticket was migrated from Redmine. As such, not all \n"
         "information was able to be captured in the transition. Below is\n" 
         "a complete record of the original redmine ticket.\n"
         "\n"
         "Ticket number: %s\n"
         "Status: %s\n"
         "Project: %s\n"
         "Tracker: %s\n"
         "Priority: %s\n"
         "Subject: %s\n"
         "Assigned to: %s\n"
         "Category: %s\n"
         "Target version: %s\n"
         "Author: %s\n"
         "Start: %s\n"
         "Due date: %s\n"
         "%% Done: %s\n"
         "Estimated time: %s\n"
         "Created: %s\n"
         "Updated: %s\n"
         "Likelihood: %s\n"
         "Severity: %s\n"
         "Found in version: %s\n"
         "Impact: %s\n"
         "Expected Use: %s\n"
         "OS: %s\n"
         "Support Group: %s\n"
         "Description:\n %s\n\n"
         "Comments:\n%s\n" 
          )
    ticket_num = row['#'].encode('utf-8')
    comments   = ""
    if ticket_num in comment_map:
        for com in comment_map[ticket_num]:
            comments += "%s\n" % str(com)

    return  template % (ticket_num, row['Status'].encode('utf-8'),  
                        row['Project'].encode('utf-8'), 
                        row['Tracker'].encode('utf-8'), 
                        row['Priority'].encode('utf-8'), 
                        row['Subject'].encode('utf-8'),
                        row['Assigned to'].encode('utf-8'), 
                        row['Category'].encode('utf-8'), 
                        row['Target version'].encode('utf-8'),
                        row['Author'].encode('utf-8'), 
                        row['Start'].encode('utf-8'), 
                        row['Due date'].encode('utf-8'), 
                        row['% Done'].encode('utf-8'), 
                        row['Estimated time'].encode('utf-8'), 
                        row['Created'].encode('utf-8'),
                        row['Updated'].encode('utf-8'), 
                        row['Likelihood'].encode('utf-8'), 
                        row['Severity'].encode('utf-8'),
                        row['Found in Version'].encode('utf-8'), 
                        row['Impact'].encode('utf-8'), 
                        row['Expected Use'].encode('utf-8'),
                        row['OS'].encode('utf-8'), 
                        row['Support Group'].encode('utf-8'), 
                        row['Description'].encode('utf-8'), 
                        comments.encode('utf-8'))


def close_milestones(milestones, number_map, attempts=0):
    """
        Close a list of milestones. 
    """
    for ms in milestones:
        url = 'https://api.github.com/repos/%s/%s/milestones/%s' % (REPO_OWNER, 
            REPO_NAME, number_map[ms])
        session = requests.Session()
        session.auth = (USERNAME, PASSWORD)
        issue = {'state': 'closed'}

        sleep(SHORT_WAIT)
        response = session.post(url, json.dumps(issue, encoding='latin1'))
        if response.status_code == 200:
            print 'Successfully close milestone "%s"' % ms
        else:
            print 'ERROR: Could not close milestone "%s"' % ms
            print 'Response:', response.content

            if exceeded_limit(response):
                if attempts >= MAX_ATTEMPTS:
                    print "ERROR: reached maximum attempts. Exiting..."
                    exit(1)
                #
                # Github only allows a certain amount of 
                # contact before it needs some space. 
                #
                print "Attempting to wait out the block..."
                print "Will try again in %i seconds" % LONG_WAIT
                sleep(LONG_WAIT)
                close_milestones([ms], 
                                 number_map, 
                                 attempts + 1)
    

def milestone_is_open(ms):
    """
        Determine if a milestone should be set to open or not. 
    """
    parts = [int(p) for p in str(ms).split('.')]
    if parts[0] >= 3:
        return True
    if len(parts) == 3:
        if (parts[0] == 2 and 
            parts[1] >= 13 and
            parts[2] >= 3):
            return True
    return False


def label_to_index(label):
    """
        A very simple map which returns an integer
        for a given label. This is used to categorize 
        labels and assign indicies. 
    """
    lower_label = label.lower()
    if 'bug' in lower_label:
        return 0
    if 'docs' in lower_label:
        return 1
    if 'expected use' in lower_label:
        return 2
    if 'feature' in lower_label:
        return 3
    if 'impact' in lower_label:
        return 4
    if 'likelihood' in lower_label:
        return 5
    if 'priority' in lower_label:
        return 6
    if 'severity' in lower_label:
        return 7
    if 'support group' in lower_label:
        return 8


def label_color_mapper(label):
    """
        Map categorical VisIt labels to colors. 
    """
    hot_colors   = ["3df5f3", "f5ea3d", "fa8561", "f68f09", "f91515"]
    blues        =  ["111E6C", "81D8D0", "003152", "0E4D92", "0F52BA",
                    "008ECC", "008081", "4682B4", "73C2FB"]

    return blues[label_to_index(label)]


def extract_labels(row, found):
    """
        Extract and format labels from a VisIt redmine ticket csv row. 
    """

    #
    # Labels that contain these words will not be migrated. 
    #
    exclusion_flags = ['any', 'all']

    label_dict = {}
    label_titles = ['Tracker', 'Priority', 'Category', 'Likelihood', 'Severity',
        'Impact', 'Expected Use', 'Support Group']

    for title in label_titles:
        label = row[title]
        if label == '' or label in found:
            continue

        if filter(lambda x: x in label.lower(), exclusion_flags):
            continue

        if title not in label_dict:
            label_dict[title] = []

        if label not in label_dict[title]:
             label_dict[title].append(label)

    #
    # Many of these could be compacted into a single smart loop, 
    # but some of them require little tweeks. I've decided on the
    # messy route.
    #
    if 'Severity' in label_dict:
        for i in range(len(label_dict['Severity'])):
            label_dict['Severity'][i] = "Severity: %s" % label_dict['Severity'][i]
        
    if 'Likelihood' in label_dict:
        for i in range(len(label_dict['Likelihood'])):
            label_dict['Likelihood'][i] = "Likelihood: %s" % label_dict['Likelihood'][i]
        
    if 'Expected Use' in label_dict:
        for i in range(len(label_dict['Expected Use'])):
            label_dict['Expected Use'][i] = "Expected Use: %s" % label_dict['Expected Use'][i]
        
    if 'Priority' in label_dict:
        for i in range(len(label_dict['Priority'])):
            label_dict['Priority'][i] = "Priority: %s" % label_dict['Priority'][i]
        
    if 'Impact' in label_dict:
        for i in range(len(label_dict['Impact'])):
            label_dict['Impact'][i] = "Impact: %s" % label_dict['Impact'][i]
        
    if 'Support Group' in label_dict:
        for i in range(len(label_dict['Support Group'])):
            label_dict['Support Group'][i] = "Support Group: %s" % label_dict['Support Group'][i]
        
    out_labels = []
    for key in label_dict:
        for label in label_dict[key]:
            if label.strip() != "" and label.strip() not in found:
                out_labels.append(label.strip())

    return out_labels


def extract_milestones(row, found):
    """
        Extract the milestone from a row. 
    """
    target = 'Target version'

    mile_s = row[target]
    if mile_s == '' or mile_s in found:
        return []

    return [mile_s]


def create_github_label(name, 
                        color, 
                        description = None, 
                        attempts    = 0):
    """
        Create a label on github issues. 
    """
    url = 'https://api.github.com/repos/%s/%s/labels' % (REPO_OWNER, REPO_NAME)
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'name': name,
             'color': color,
             'description': description}

    sleep(SHORT_WAIT)
    response = session.post(url, json.dumps(issue, encoding='latin1'))
    if response.status_code == 201:
        print 'Successfully created label "%s"' % name
    else:
        print 'ERROR: Could not create label "%s"' % name
        print 'Response:', response.content

        if exceeded_limit(response):
            if attempts >= MAX_ATTEMPTS:
                print "ERROR: reached maximum attempts. Exiting..."
                exit(1)
            #
            # Github only allows a certain amount of 
            # contact before it needs some space. 
            #
            print "Attempting to wait out the block..."
            print "Will try again in %i seconds" % LONG_WAIT
            sleep(LONG_WAIT)
            create_github_label(name, 
                                color, 
                                description, 
                                attempts + 1)


def create_github_milestone(title, 
                            state       = 'open',
                            description = None, 
                            due_on      = None,
                            attempts    = 0):
    """
        Create a label on github issues. 
    """
    url = 'https://api.github.com/repos/%s/%s/milestones' % (REPO_OWNER, REPO_NAME)
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'title': title,
             'state': state,
             'description': description,
             'due_on': due_on}

    sleep(SHORT_WAIT)
    response = session.post(url, json.dumps(issue, encoding='latin1'))
    if response.status_code == 201:
        print 'Successfully created milestone "%s"' % title
        return json.loads(response.content)['number']
        
    else:
        print 'ERROR: Could not create milestone "%s"' % title
        print 'Response:', response.content

        if exceeded_limit(response):
            if attempts >= MAX_ATTEMPTS:
                print "ERROR: reached maximum attempts. Exiting..."
                exit(1)
            #
            # Github only allows a certain amount of 
            # contact before it needs some space. 
            #
            print "Attempting to wait out the block..."
            print "Will try again in %i seconds" % LONG_WAIT
            sleep(LONG_WAIT)
            create_github_milestone(title, 
                                    state, 
                                    description, 
                                    due_on, 
                                    attempts + 1)


def close_github_issue(issue_url, 
                       attempts = 0):
    """
        Close a github issue.
    """
    sleep(SHORT_WAIT)
    print "Setting state to closed"
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'state': "closed"}
    response = session.post(issue_url, json.dumps(issue, encoding='latin1'))
    if response.status_code == 200:
        print 'Successfully closed issue'
    else:
        print 'ERROR: Could not close issue'
        print 'Response:', response.content

        if exceeded_limit(response):
            if attempts >= MAX_ATTEMPTS:
                print "ERROR: reached maximum attempts. Exiting..."
                exit(1)
            #
            # Github only allows a certain amount of 
            # contact before it needs some space. 
            #
            print "Attempting to wait out the block..."
            print "Will try again in %i seconds" % LONG_WAIT
            sleep(LONG_WAIT)
            close_github_issue(issue_url, 
                               attempts + 1)


def create_github_issue(title, 
                        body      = None, 
                        assignees = [], 
                        milestone = None, 
                        labels    = [], 
                        state     = "open",
                        attempts  = 0):
    """
        Create a new github issue. If the issue is closed, close it after 
        its creation. 
    """
    main_url = 'https://api.github.com/repos/%s/%s/issues' % (REPO_OWNER, REPO_NAME)
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'title': title,
             'body': body,
             'assignees': assignees,
             'milestone': milestone,
             'labels': labels}

    sleep(SHORT_WAIT)
    issue_url = ""
    response = session.post(main_url, json.dumps(issue, encoding='latin1'))
    if response.status_code == 201:
        print 'Successfully created Issue "%s"' % title
        issue_url = json.loads(response.content)['url']
    else:
        print 'ERROR: Could not create Issue "%s"' % title
        print 'Response:', response.content

        if exceeded_limit(response):
            if attempts >= MAX_ATTEMPTS:
                print "ERROR: reached maximum attempts. Exiting..."
                exit(1)
            #
            # Github only allows a certain amount of 
            # contact before it needs some space. 
            #
            print "Attempting to wait out the block..."
            print "Will try again in %i seconds" % LONG_WAIT
            sleep(LONG_WAIT)
            create_github_issue(title, 
                                body, 
                                assignees, 
                                milestone, 
                                labels, 
                                state,
                                attempts + 1)

        elif invalid_assignee(response):
            #
            # The assignee can't be mapped on github, so 
            # just leave it blank. 
            #
            print "Re-submitting ticket with blank assignee."
            create_github_issue(title, 
                                body, 
                                [], 
                                milestone, 
                                labels, 
                                state,
                                attempts + 1)
        else:
            return

    if state == 'closed':
        if issue_url == "":
            print "ERROR: failed to retrieve issue url"
            return
        close_github_issue(issue_url)


def migrate_issues(csv_path, 
                   name_map, 
                   comment_map,
                   do_tickets       = True, 
                   do_labels        = True,
                   do_milestones    = True, 
                   ignore_assignees = False):
    """
        Migrate redmine issues from a csv file to github issues. 
    """
    csv_files      = os.path.join(csv_path, "*.csv")
    fin_labels     = []
    fin_mile_s     = []
    mile_s_numbers = {}
    seen_tickets   = []
    closed_ms      = []


    for f_pth in glob.glob(csv_files):
        with open(f_pth, "r") as csvfile:
            print "\nOpening file: %s" % f_path
            reader = csv.DictReader(csvfile)

            if do_labels:
                print "\nCreating labels "
                f_labels = []
                for row in reader:
                    f_labels.extend(extract_labels(row, fin_labels))
                    fin_labels.extend(f_labels)

                for label in f_labels:
                    create_github_label(label, label_color_mapper(label))
                print "Finished ceating labels!"

            if do_milestones:
                print "\nCreating milestones"
                csvfile.seek(0)
                next(reader)
                mile_s = []
                for row in reader:
                    mile_s.extend(extract_milestones(row, fin_mile_s))
                    fin_mile_s.extend(mile_s)
                for ms in mile_s:
                    if not milestone_is_open(ms):
                        closed_ms.append(ms)
                    mile_s_numbers[ms] = create_github_milestone(ms, 'open')
                print "Finished ceating milestones!"

            if do_tickets:
                print "\nCreating tickets"
                csvfile.seek(0)
                next(reader)
                for row in reader:
                    #
                    # Retrieve redmine specific info that will need to be 
                    # added to the description. 
                    #
                    author      = row['Author']               
                    created     = row['Created']               
                    updated     = row['Updated']
                    t_num       = row['#']

                    if t_num in seen_tickets:
                        msg = ("We've already proccessed ticket %s..."
                               "Skipping it" % t_num)
                        print msg 
                        continue
                    seen_tickets.append(t_num)

                    closed      = ["Rejected", "Resolved", "Expired"]

                    if ignore_assignees:
                        assignees = []
                    else:
                        assignees   = [name_map[assignee] if assignee in name_map else "" 
                            for assignee in row['Assigned to'].split(",")]

                    title       = row['Subject']
                    desc        = row['Description']
                    state       = "closed" if str(row['Status']) in closed else "open"
                    labels      = extract_labels(row, [])
     
                    #TODO: If we're not creating milestones, we need to somehow
                    #      get their numbers from github...
                    milestone   = None

                    if row['Target version'] != '' and do_milestones:
                        if row['Target version'] not in mile_s_numbers:
                            print "ERROR: unable to find number for milestone!"
                            print "Aborting this ticket!"
                            continue
                        milestone = mile_s_numbers[row['Target version']]
    
                    body = "%s\n\n%s" % (desc, create_redmine_tag(row, comment_map))
 
                    create_github_issue(title, 
                                        body, 
                                        assignees, 
                                        milestone, 
                                        labels, 
                                        state)

                print "Finished creating tickets!"
    print "Finished all files in: %s" % csv_path
    print "Closing appropriate milestones"
    close_milestones(closed_ms, mile_s_numbers)
    print "FINISHED!"


if __name__ == '__main__':
    """
        Launch the program. 
    """
    parser = argparse.ArgumentParser()
    parser.add_argument("csv_path", help="path to csv files", type=str)
    parser.add_argument("name_map_file", help="""a json file mapping VisIt 
        redmine names to their github account names""", type=str)
    parser.add_argument("comments_file", help="""a json file mapping redmine
        ticket numbers to their comments""", type=str)
    parser.add_argument("--no_tickets", help="don't create tickets", default=False,
        action="store_true") 
    parser.add_argument("--no_labels", help="don't create labels", default=False,
        action="store_true") 
    parser.add_argument("--no_milestones", help="don't create milestones", default=False,
        action="store_true") 
    parser.add_argument("--ignore_assignees", help="ignore assignees", default=False,
        action="store_true") 
    args = parser.parse_args()

    do_tickets       = True
    do_labels        = True
    do_milestones    = True
    ignore_assignees = False

    with open(args.name_map_file, 'r') as json_f:
        name_map = json.load(json_f)

    with open(args.comments_file, 'r') as json_f:
        comment_map = json.load(json_f)

    for key, value in name_map.iteritems():
        name_map[key] = str(value)

    if args.no_tickets:
        do_tickets = False

    if args.no_labels:
        do_labels = False

    if args.no_milestones:
        do_milestones = False

    if args.ignore_assignees:
        ignore_assignees = True

    migrate_issues(args.csv_path, 
                   name_map, 
                   comment_map,
                   do_tickets, 
                   do_labels,
                   do_milestones,
                   ignore_assignees)


