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
import sys
from time import sleep
import random
import argparse
import re
from authentication import *

SHORT_WAIT    = 3
MAX_ATTEMPTS  = 5
LONG_WAIT     = 3700
BLOCK_FLAGS   = ["temporarily blocked from content", "API rate limit exceeded"]

GRADATION_MAP = {}
GRADATION_MAP.update(dict.fromkeys(['1', '2'], 'low'))
GRADATION_MAP.update(dict.fromkeys(['3'], 'medium'))
GRADATION_MAP.update(dict.fromkeys(['4', '5'], 'high'))


def refine_target_version(tv):
    """
        There are a couple of very old target versions that
        are in a format no longer used. We need to convert 
        these for github to accept. 
    """
    if 'HDF5' in tv:
         return tv.split('-')[-1]
    return tv


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


def url_link_map(text):
    """
        In redmine, url links are of the form "linkname":url
        In github, url links are of the form [linkname](url)

        Given some text, this function will replace all of the 
        redmine style links with github style links. 
    """
    words = text.split()

    for i in range(len(words)):
        block = words[i]
        url_links = [(sub.start(), sub.end()) for sub in
                     re.finditer("(?P<url>https?://[^\s]+)", block)
                     if sub.start() >= 0 and block[sub.start()-1] == ':']

        for idxs in url_links:
            start, stop = idxs
            #
            # The first block is of the form 
            #    foo"linkname":
            # we want this to become foo[linkname]
            #
            block_a = block[:start-2].rsplit('"', 1)
            block_a = "[".join(block_a) + "]"

            #
            # url, once isolated, just needs parens.
            #
            url     = "(" + block[start:stop] + ")"

            #
            # Last section, if present, is unchanged. 
            #
            block_b = block[stop:]

            words[i] = block_a + url + block_b

    return ' '.join(words)


def cleanup_text(text):
    """
        Cleanup the text from redmine. 

        There are instances where a redmine symbol does not map
        correctly to github. So we replace those symbols here. 
    """
    #
    # We need to replace redmine markings with their
    # github equivalents, if available. If not, they 
    # are replace with empty strings.
    #
    redmine_markings = ["@", "*", "+", "-"]
    github_mappings  = ["`", "**", "", ""]
    num_marks        = len(redmine_markings)
    count            = [0] * num_marks
    indicies = {}
    for sym in github_mappings:
        indicies[sym] = []

    #
    # First, we should remove all non ascii characters.
    #
    text_chars = [i for i in text if ord(i) < 128] 

    #
    # We only want to replace PAIRS of redmine markings 
    # that are not separated by a new line. 
    # The algorithm:
    # Find all indicies for each pair of redmine marking
    # not separated by a new line. 
    # Replace all characters at these indicies with their
    # github mappings. 
    #

    #
    # Iterate through the characters. 
    #
    for i in range(len(text_chars)):
        #
        # Iterate through the redming markings. 
        #
        for j in range(num_marks):
            if text_chars[i] == redmine_markings[j]:
                indicies[github_mappings[j]].append(i)
                count[j] += 1
            #
            # If we've encountered a new line character, 
            # we need to remove the last non-pair elements. 
            #
            elif text_chars[i] == '\n':
                for c in range(len(count)):
                    if (count[c] % 2) > 0:
                        indicies[github_mappings[c]].pop()
                        count[c] -= 1

    for sym in indicies.keys():
        _max = len(indicies[sym])
        i = 1
        while i < _max:
            text_chars[indicies[sym][i]]   = sym
            text_chars[indicies[sym][i-1]] = sym
            i += 2

    #
    # The final stage is to map redmine style url links to 
    # github style. 
    #
    return url_link_map(''.join(text_chars))



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
    ticket_num = row['#']
    comments   = ""
    if ticket_num in comment_map:
        for com in comment_map[ticket_num]:
            comments += "%s\n" % com.encode('utf-8')

    return  template % (ticket_num, row['Status'],  
                        "VisIt", 
                        row['Tracker'], 
                        row['Priority'], 
                        cleanup_text(row['Subject']),
                        row['Assigned to'], 
                        row['Category'], 
                        row['Target version'],
                        row['Author'], 
                        row['Start'], 
                        row['Due date'], 
                        row['% Done'], 
                        row['Estimated time'], 
                        row['Created'],
                        row['Updated'], 
                        row['Likelihood'], 
                        row['Severity'],
                        row['Found in Version'], 
                        row['Impact'], 
                        row['Expected Use'],
                        row['OS'], 
                        row['Support Group'], 
                        cleanup_text(row['Description']), 
                        cleanup_text(comments))


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
    if parts[0] == 3:
        return True
    return False


def map_gradation(num):
    """
    """
    if num not in GRADATION_MAP:
        print "ERROR: could not find gradation level in map..."
        print "Assigning empty level"
        return "" 
    return GRADATION_MAP[num] 


#NOTE: the github api's ability to add descriptions
#      to labels appears to be broken. 
def label_descriptions(label):
    """
        Map some descriptions to labels. 
    """
    if 'asc' in label: 
        return "related to an asc funded project"
    if 'grizit' in label:
        return "related to the grizit project"
    if 'likelihood high' in label:
        return "high likelihood a user would encounter"
    if 'likelihood low' in label:
        return "low likelihood a user would encounter"
    if 'likelihood medium' in label:
        return "medium likelihood a user would encounter"
    if 'scidac' in label:
        return "related to a scidac funded project"
    if 'vtk8' in label:
        return "related to the vtk8 migration"
    return ""


def label_to_index(label):
    """
        A very simple map which returns an integer
        for a given label. This is used to categorize 
        labels and assign indicies. 
    """
    lower_label = label.lower()
    if 'docs' in lower_label:
        return 0
    if 'impact' in lower_label:
        return 1
    if 'likelihood' in lower_label:
        return 2
    if 'priority' in lower_label:
        return 3
    if 'severity' in lower_label:
        return 4
    if 'reviewed' in lower_label:
        return 5
    if 'vtk8' in lower_label:
        return 6
    if 'crash' in lower_label:
        return 7
    if 'wrong results' in lower_label:
        return 8
    else:
        # all groups
        return 9


def label_color_mapper(label):
    """
        Map categorical VisIt labels to colors. 
    """
    hot_colors   = ["3df5f3", "f5ea3d", "fa8561", "f68f09", "f91515"]
    blues        =  ["111E6C", "81D8D0", "003152", "0E4D92", "0F52BA",
                    "008ECC", "008081", "4682B4", "73C2FB", "00ACC1"]

    return blues[label_to_index(label)]


def extract_labels(row, exclude):
    """
        Extract and format labels from a VisIt redmine ticket csv row. 
    """
    #
    # Labels that contain these words will not be migrated. 
    #
    exclusion_flags = ['any', 'all']

 
    #
    # Standar labels must undergo exclusion testing. 
    #
    label_titles = ['Tracker', 'Priority', 'Category', 'Likelihood', 'Severity',
        'Support Group', 'Status']
    #
    # Special cases are exempt from exclusion checking. 
    #
    special_cases = ['Description', 'Subject']

    label_dict   = {}

    for title in label_titles:
        label = row[title]
        if label == '' or label == '-' or label in exclude:
            continue

        if filter(lambda x: x in label.lower(), exclusion_flags):
            continue

        if title not in label_dict:
            label_dict[title] = label.lower().strip()

    for title in special_cases:
        label_dict[title] = row[title].lower().strip()

    out_labels = []
    #
    # Iterate over our labels, reformat as needed, and
    # add the new ones to our outgoing list. 
    #
    for key in label_dict.iterkeys():

        if key == 'Status':
            if label_dict[key] != 'new':
                new_label = 'reviewed'
                if new_label not in exclude:
                    out_labels.append(new_label)
            if label_dict[key] == "expired":
                new_label = "invalid"
                if new_label not in exclude:
                    out_labels.append(new_label)
            if label_dict[key] == "rejected":
                new_label = "wontfix"
                if new_label not in exclude:
                    out_labels.append(new_label)
            
        elif key == 'Severity':
            num = label_dict[key].strip()[0]
            sev = map_gradation(num)
            new_label = "severity %s" % sev
            if new_label not in exclude:
                out_labels.append(new_label)
            #
            # For severity level 4, we also add crash and wrong results
            # labels. 
            #
            if num == "4":
                if "crash" not in exclude and "wrong results" not in exclude:
                   out_labels.append("crash")
                   out_labels.append("wrong results")

        elif key == 'Likelihood':
            num = label_dict[key].strip()[0]
            sev = map_gradation(num)
            new_label = "likelihood %s" % sev
            if new_label not in exclude:
                out_labels.append(new_label)

        elif key == 'Priority':
            keepers = ["high", "urgent", "immediate"]
            if label_dict[key] in keepers:
                new_label = "priority" 
                if new_label not in exclude:
                    out_labels.append(new_label)
        
        elif key == 'Support Group':
            sglab = label_dict[key] 
            new_label = sglab.split('/')[1].strip() if '/' in sglab else sglab
            if new_label not in exclude:
                out_labels.append(new_label)

        #
        # Special cases for descripton and subject: 
        # if VTK-8 is mentioned in either, assign a new vtk-8 label. 
        #
        elif key == 'Description' or key == 'Subject':
            if "vtk8" not in exclude:
                content = label_dict[key] 
                variations = ['vtk8', 'vtk-8', 'vtk 8']
                for var in variations:
                    if var in content:
                        out_labels.append("vtk8")
                        break

        else:
            f_lab = label_dict[key].strip()
            if f_lab == "feature":
                f_lab = "enhancement" 
            if f_lab != "" and f_lab not in exclude:
                out_labels.append(f_lab)

    return out_labels


def extract_milestones(row, exclude):
    """
        Extract the milestone from a row. 
    """
    target = 'Target version'

    mile_s = row[target]
    if mile_s == '' or mile_s == '-' or mile_s in exclude:
        return []

    return [mile_s]


def create_github_label(name, 
                        color, 
                        description = '', 
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
                            state    = 'open',
                            attempts = 0):
    """
        Create a label on github issues. 
    """
    url = 'https://api.github.com/repos/%s/%s/milestones' % (REPO_OWNER, REPO_NAME)
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'title': title,
             'state': state
            }

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
                        body      = '', 
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

    ticket_number = -1

    sleep(SHORT_WAIT)
    issue_url = ""
    response = session.post(main_url, json.dumps(issue, encoding='latin1'))
    if response.status_code == 201:
        print 'Successfully created Issue "%s"' % title
        rcont         = json.loads(response.content)
        issue_url     = rcont['url']
        ticket_number = rcont['number'] 
        
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
            ticket_number = create_github_issue(title, 
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
            ticket_number = create_github_issue(title, 
                                                body, 
                                                [], 
                                                milestone, 
                                                labels, 
                                                state,
                                                attempts + 1)
        else:
            return ticket_number

    if state == 'closed':
        if issue_url == "":
            print "ERROR: failed to retrieve issue url"
            return ticket_number
        close_github_issue(issue_url)

    return ticket_number


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
    #
    # fin_labels contains labels we've alread added or don't need to
    # create because they're on github already. excludes are labels
    # we don't want to include. 
    #
    fin_labels     = ["bug", "enhancement", "expired", "rejected", 
                      "wontfix", "invalid"]
    excludes       = ["developer review", "pending", "new", "doe", "dod",
                      "neams", "ale3d"]
    full_excludes  = excludes + fin_labels 
    fin_mile_s     = []
    mile_s_numbers = {}
    seen_tickets   = []
    closed_ms      = []
    ticket_map     = {}


    for f_pth in glob.glob(csv_files):
        with open(f_pth, "r") as csvfile:
            print "\nOpening file: %s" % f_pth
            reader = csv.DictReader(csvfile)

            if do_labels:
                print "\nCreating labels "
                f_labels = []
                for row in reader:
                    extracts = extract_labels(row, full_excludes)
                    f_labels.extend(extracts)
                    full_excludes.extend(extracts)

                for label in f_labels:
                    create_github_label(label, 
                                        label_color_mapper(label), 
                                        label_descriptions(label))
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
                    refined = refine_target_version(ms)
                    if not milestone_is_open(refined):
                        closed_ms.append(refined)
                    mile_s_numbers[refined] = create_github_milestone(refined, 'open')
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
                    old_t_num   = row['#']

                    if old_t_num in seen_tickets:
                        msg = ("We've already proccessed ticket %s..."
                               "Skipping it" % old_t_num)
                        print msg 
                        continue
                    seen_tickets.append(old_t_num)

                    closed      = ["Rejected", "Resolved", "Expired"]

                    if ignore_assignees:
                        assignees = []
                    else:
                        assignees = [name_map[assignee] if assignee in name_map else "" 
                            for assignee in row['Assigned to'].split(",")]

                    title       = cleanup_text(row['Subject'])
                    desc        = cleanup_text(row['Description'])
                    state       = "closed" if str(row['Status']) in closed else "open"
                    labels      = extract_labels(row, excludes)
     
                    #TODO: If we're not creating milestones, we need to somehow
                    #      get their numbers from github...
                    milestone   = None

                    tv = refine_target_version(row['Target version'])
                    if tv != '' and tv != '-' and do_milestones:
                        if tv not in mile_s_numbers:
                            msg = "unable to find milestone for %s !" % tv
                            print "ERROR: %s" % msg
                            print "Aborting this ticket!"
                            continue
                        milestone = mile_s_numbers[tv]
    
                    body = "%s\n\n%s" % (desc, create_redmine_tag(row, comment_map))
 
                    new_t_num = create_github_issue(title, 
                                                    body, 
                                                    assignees, 
                                                    milestone, 
                                                    labels, 
                                                    state)
                    #
                    # Map our redmine ticket number to github ticket numbers. 
                    #
                    ticket_map[old_t_num] = str(new_t_num)
 
                print "Finished creating tickets!"
    print "Finished all files in: %s" % csv_path
    print "Closing appropriate milestones"
    close_milestones(closed_ms, mile_s_numbers)

    #
    # Save our ticket map. 
    #
    with open("ticket_map.json", "w") as out_f:
        json.dump(ticket_map, out_f)

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


