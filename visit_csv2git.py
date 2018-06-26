"""
This is a specialized script to migrate VisIt issues from redmine to 
github issues. 

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
import argparse
from create_git_labels import *
from authentication import *

def extract_labels(row, in_labels):

    label_dict = {}
    label_titles = ['Tracker', 'Priority', 'Category', 'Likelihood', 'Severity',
        'Found in Version', 'Impact', 'Expected Use', 'OS', 'Support Group', 'Target version']

    for title in label_titles:
        label = row[title]
        if label == '':
            continue

        if title not in label_dict:
            label_dict[title] = []

        if label not in label_dict[title]:
             label_dict[title].append(label)

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
        
    if 'Target version' in label_dict:
        for i in range(len(label_dict['Target version'])):
            label_dict['Target version'][i] = "Target Version: %s" % label_dict['Target version'][i]

    if 'OS' in label_dict:
        for i in range(len(label_dict['OS'])):
            label_dict['OS'][i] = "OS: %s" % label_dict['OS'][i]

    out_labels = []
    for key in label_dict:
        for label in label_dict[key]:
            if label.strip() != "" and label.strip() not in in_labels:
                out_labels.append(label.strip())
    return out_labels


def make_github_issue(title, body=None, assignees=None, milestone=None, labels=None, state="open"):
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
        print('Successfully created Issue "%s"' % title)
        issue_url = json.loads(response.content)['url']
    else:
        print('Could not create Issue "%s"' % title)
        print('Response:', response.content)
        return

    if state == 'closed':
        sleep(3)
        print "Setting state to closed"
        session = requests.Session()
        session.auth = (USERNAME, PASSWORD)
        issue = {'state': "closed"}
        response = session.post(issue_url, json.dumps(issue))
        if response.status_code == 200:
            print('Successfully closed issue "%s"' % title)
        else:
            print('Could not close issue "%s"' % title)
            print('Response:', response.content)
            return


def migrate_issues(csv_path, do_tickets=True, do_labels=True):

    csv_files  = os.path.join(csv_path, "*.csv")
    fin_labels = []

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
                    create_github_labels(label, label_color_mapper(label))
                print "Finished ceating labels!"

            if do_tickets:
                print "\nCreating tickets"
                csvfile.seek(0)
                for row in reader:
                    closed      = ["Rejected", "Resolved"]
                    #FIXME: this needs uncommenting once add people 
                    #assignees   = [assignee for assignee in row['Assigned to'].split(",")]
                    assignees   = ["aowen87"]
                    title       = row['Subject']
                    body        = row['Description']
                    state       = "closed" if row['Status'] in closed else "open"
                    labels      = []
                    milestone   = None

                    make_github_issue(title, body, assignees, milestone, labels, state)

                print "Finished creating tickets!"


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("csv_path", help="path to csv files", type=str)
    parser.add_argument("--no_tickets", help="don't create tickets", default=False,
        action="store_true") 
    parser.add_argument("--no_labels", help="don't create labels", default=False,
        action="store_true") 
    args = parser.parse_args()

    do_tickets = True
    do_labels  = True

    if args.no_tickets:
        do_tickets = False

    if args.no_labels:
        do_labels = False

    migrate_issues(args.csv_path, do_tickets, do_labels)


#files = [f for f in os.listdir("./") if (f.endswith(".csv") and not f.startswith("."))]
#
#for f_name in files:
#    print "opening ", f_name
#    with open(f_name, "r") as csvfile:
#        reader = csv.DictReader(csvfile)
#
#        for row in reader:
#            closed      = ["Rejected", "Resolved"]
#            #FIXME: this needs uncommenting once add people 
#            #assignees   = [assignee for assignee in row['Assigned to'].split(",")]
#            assignees   = ["aowen87"]
#            title       = row['Subject']
#            body        = row['Description']
#            state       = "closed" if row['Status'] in closed else "open"
#            labels      = []
#            milestone   = None
#
#            labels = extract_labels(row)
#
#            make_github_issue(title, body, assignees, milestone, labels, state)
#
