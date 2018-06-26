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

def extract_labels(row):

    labels = {}
    label_titles = ['Tracker', 'Priority', 'Category', 'Likelihood', 'Severity',
        'Found in Version', 'Impact', 'Expected Use', 'OS', 'Support Group', 'Target version']

    for title in label_titles:
        label = row[title]
        if label == '':
            continue

        if title not in labels:
            labels[title] = []

        if label not in labels[title]:
             labels[title].append(label)

    if 'Severity' in labels:
        for i in range(len(labels['Severity'])):
            labels['Severity'][i] = "Severity: %s" % labels['Severity'][i]

    if 'Found in Version' in labels:    
        for i in range(len(labels['Found in Version'])):
            labels['Found in Version'][i] = "version: %s" % labels['Found in Version'][i]
        
    if 'Likelihood' in labels:
        for i in range(len(labels['Likelihood'])):
            labels['Likelihood'][i] = "Likelihood: %s" % labels['Likelihood'][i]
        
    if 'Expected Use' in labels:
        for i in range(len(labels['Expected Use'])):
            labels['Expected Use'][i] = "Expected Use: %s" % labels['Expected Use'][i]
        
    if 'Priority' in labels:
        for i in range(len(labels['Priority'])):
            labels['Priority'][i] = "Priority: %s" % labels['Priority'][i]
        
    if 'Impact' in labels:
        for i in range(len(labels['Impact'])):
            labels['Impact'][i] = "Impact: %s" % labels['Impact'][i]
        
    if 'Support Group' in labels:
        for i in range(len(labels['Support Group'])):
            labels['Support Group'][i] = "Support Group: %s" % labels['Support Group'][i]
        
    if 'Target version' in labels:
        for i in range(len(labels['Target version'])):
            labels['Target version'][i] = "Target Version: %s" % labels['Target version'][i]

    if 'OS' in labels:
        for i in range(len(labels['OS'])):
            labels['OS'][i] = "OS: %s" % labels['OS'][i]

    labels_lst = []

    for key in labels:
        for label in labels[key]:
            if label.strip() != "":
                labels_lst.append(label.strip())

    return labels_lst


def make_github_issue(title, body=None, assignees=None, milestone=None, labels=None, state="open"):

    print "Attempting to create issue %s" % title
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

    csv_files = os.path.join(csv_path, "*.csv")

    for f_pth in glob.glob(csv_files):
        with open(f_pth, "r") as csvfile:
            reader = csv.DictReader(csvfile)
            labels = []

            if do_labels:
                print "\nCreating labels "
                for row in reader:
                    labels = extract_labels(row)
                    for label in labels:
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
