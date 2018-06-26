import json
import random
import requests
import csv
from time import sleep
from authentication import *

def create_github_labels(name, color, description=None):
    url = 'https://api.github.com/repos/%s/%s/labels' % (REPO_OWNER, REPO_NAME)
    session = requests.Session()
    session.auth = (USERNAME, PASSWORD)
    issue = {'name': name,
             'color': color,
             'description': description}

    sleep(3)
    reciever = session.post(url, json.dumps(issue))
    if reciever.status_code == 201:
        print('Successfully created label "%s"' % name)
    else:
        print('Could not create label "%s"' % name)
        print('Response:', reciever.content)

def label_color_mapper(tag):
    hot_colors   = ["3df5f3", "f5ea3d", "fa8561", "f68f09", "f91515"]
    nice_colors  = ["6bd2db", "0ea7b5", "0c457d", "008080", "0000ff", 
                    "800080", "ffb6c1", "003366", "20b2aa", "660066",
                    "31698a", "6dc066"]
    if "-" in tag:
        digits = [int(d) for d in tag.split() if d.isdigit()]
        if len(digits) > 1:
            print "ERROR: multiple digits found in color prospect!"
            print tag
            exit(1)
        return hot_colors[digits[0]-1]
    else:
        return nice_colors[random.randint(0, len(nice_colors)-1)]

#with open('tags.csv', 'r') as csvfile:
#    reader = csv.DictReader(csvfile)
#    for row in reader:
#        color = color_mapper(row['name'])      
#        print "name: ", str(row['name'])
#        create_github_labels(row['name'], color, row['description'])

