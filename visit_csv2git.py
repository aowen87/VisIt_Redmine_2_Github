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

MAX_ATTEMPTS  = 5
WAIT_TIME     = 1800 
BLOCK_FLAGS   = ["temporarily blocked from content", "API rate limit exceeded"]


def exceeded_limit(response):
    for flag in BLOCK_FLAGS:
        if flag in response.content: 
            return True
    return False


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


def label_color_mapper(label):
    """
        Map colors to VisIt labels. If the label has a scale 
        associated with it (such as severity), it will be given
        a color from a heat map. Otherwise, it's given a random
        'calm' color.  
    """
    hot_colors   = ["3df5f3", "f5ea3d", "fa8561", "f68f09", "f91515"]
    nice_colors  = ["6bd2db", "0ea7b5", "0c457d", "008080", "0000ff", 
                    "800080", "ffb6c1", "003366", "20b2aa", "660066",
                    "31698a", "6dc066"]
    if "-" in label:
        digits = [int(d) for d in label.split() if d.isdigit()]
        if len(digits) > 1:
            print "ERROR: multiple digits found in color prospect!"
            print label
            exit(1)
        return hot_colors[digits[0]-1]
    else:
        return nice_colors[random.randint(0, len(nice_colors)-1)]


def extract_labels(row, found):
    """
        Extract and format labels from a VisIt redmine ticket csv row. 
    """
    label_dict = {}
    label_titles = ['Tracker', 'Priority', 'Category', 'Likelihood', 'Severity',
        'Found in Version', 'Impact', 'Expected Use', 'OS', 'Support Group']

    for title in label_titles:
        label = row[title]
        if label == '' or label in found:
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

    if 'Found in Version' in label_dict:    
        for i in range(len(label_dict['Found in Version'])):
            label_dict['Found in Version'][i] = "version: %s" % label_dict['Found in Version'][i]
        
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
        
    if 'OS' in label_dict:
        for i in range(len(label_dict['OS'])):
            label_dict['OS'][i] = "OS: %s" % label_dict['OS'][i]

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

    sleep(3)
    response = session.post(url, json.dumps(issue))
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
            print "Will try again in %i seconds" % WAIT_TIME
            sleep(WAIT_TIME)
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

    sleep(3)
    response = session.post(url, json.dumps(issue))
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
            print "Will try again in %i seconds" % WAIT_TIME
            sleep(WAIT_TIME)
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
    sleep(3)
    print "Setting state to closed"
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'state': "closed"}
    response = session.post(issue_url, json.dumps(issue))
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
            print "Will try again in %i seconds" % WAIT_TIME
            sleep(WAIT_TIME)
            close_github_issue(issue_url, 
                               attempts + 1)


def create_github_issue(title, 
                        body      = None, 
                        assignees = None, 
                        milestone = None, 
                        labels    = None, 
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

    sleep(3)
    issue_url = ""
    response = session.post(main_url, json.dumps(issue))
    if response.status_code == 201:
        print 'Successfully created Issue "%s"' % title
        issue_url = json.loads(response.content)['url']
    #
    # FIXME: if we can't create an issue because the user
    #        isn't associated with the project, then re-send
    #        the ticket with a blank assignee (they'll be in the notes)
    #
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
            print "Will try again in %i seconds" % WAIT_TIME
            sleep(WAIT_TIME)
            create_github_issue(title, 
                                body, 
                                assignees, 
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
                   do_tickets    = True, 
                   do_labels     = True,
                   do_milestones = True):
    """
       Migrate redmine issues from a csv file to github issues. 
    """
    csv_files      = os.path.join(csv_path, "*.csv")
    fin_labels     = []
    fin_mile_s     = []
    mile_s_numbers = {}
    seen_tickets   = []

    body_template = ("%s\n\n\n\n"
         "-----------------------REDMINE MIGRATION-----------------------\n"
         "This ticket was migrated from Redmine. The following information\n"
         "could not be accurately captured in the new ticket:\n\n"
         "Original author: %s\n"
         "Original creation: %s\n"
         "Original update: %s\n"
         "Ticket number: %s")

    for f_pth in glob.glob(csv_files):
        with open(f_pth, "r") as csvfile:
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
                    state = 'open' if milestone_is_open(ms) else 'closed'
                    mile_s_numbers[ms] = create_github_milestone(ms, state)
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

                    #FIXME: this needs uncommenting once accounts are added to git. 
                    #assignees   = [name_map[assignee] if assignee in name_map else "" 
                    #    for assignee in row['Assigned to'].split(",")]
                    assignees   = ["aowen87"]

                    title       = row['Subject']
                    desc        = row['Description']
                    state       = "closed" if str(row['Status']) in closed else "open"
                    labels      = extract_labels(row, [])
     
                    #TODO: If we're not creating milestones, we need to somehow
                    #      get their numbers from github...
                    milestone   = None
                    
                    if row['Target version'] != '':
                        if row['Target version'] not in mile_s_numbers:
                            print "ERROR: unable to find number for milestone!"
                            print "Aborting this ticket!"
                            continue
                        milestone = mile_s_numbers[row['Target version']]
    
                    body = body_template % (desc, author, 
                        created, updated, t_num)
 
                    create_github_issue(title, 
                                        body, 
                                        assignees, 
                                        milestone, 
                                        labels, 
                                        state)

                print "Finished creating tickets!"


if __name__ == '__main__':
    """
        Launch the program. 
    """
    parser = argparse.ArgumentParser()
    parser.add_argument("csv_path", help="path to csv files", type=str)
    parser.add_argument("name_map_file", help="""a json file mapping VisIt 
        redmine names to their github account names""", type=str)
    parser.add_argument("--no_tickets", help="don't create tickets", default=False,
        action="store_true") 
    parser.add_argument("--no_labels", help="don't create labels", default=False,
        action="store_true") 
    parser.add_argument("--no_milestones", help="don't create milestones", default=False,
        action="store_true") 
    args = parser.parse_args()

    do_tickets    = True
    do_labels     = True
    do_milestones = True

    with open(args.name_map_file, 'r') as json_f:
        name_map = json.load(json_f)

    for key, value in name_map.iteritems():
        name_map[key] = str(value)

    if args.no_tickets:
        do_tickets = False

    if args.no_labels:
        do_labels = False

    if args.no_milestones:
        do_milestones = False

    migrate_issues(args.csv_path, 
                   name_map, 
                   do_tickets, 
                   do_labels,
                   do_milestones)

