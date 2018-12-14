"""
Retrive all redmine comments for visit tickets. 

@author: Alister Maguire 

"""

import os
import argparse
from bs4 import BeautifulSoup
import re
import json
from web_helpers.communication import *



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("start_ticket", type=int)
    parser.add_argument("stop_ticket", type=int)
    parser.add_argument("out_dir", type=str)
    args = parser.parse_args()
    out_dir = args.out_dir
    start   = args.start_ticket
    stop    = args.stop_ticket

    issue_comments = {}

    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    base = "https://visitbugs.ornl.gov"

    for issue in range(start, stop): 
        html        = "%s/issues/%i" % (base, issue)
        raw_html    = simple_get(html)
        if raw_html == None:
            print "Ticket #%i was not found" % issue
            continue
        html_parser = BeautifulSoup(raw_html, 'html.parser')

        if issue in issue_comments:
            print "ERROR: newly encountered issue already in dictionary?!"
            exit(1)
        else:
            issue_comments[issue] = []

        comments = html_parser.findAll('div', {'id': 'history'})
        
        if len(comments) > 0:
            changes  = comments[0].findAll('div', {'id' : re.compile('change-*')})

            for change in changes:
                para = change.findAll('p') 
                full = ""
                for each in para:
                    full += each.text.encode('utf-8')
                if full != "":
                    issue_comments[issue].append(full)

    out_f = os.path.join(out_dir, "comments.json")
    with open(out_f, "w") as outf:
        json.dump(issue_comments, outf)
    
    #for key in issue_comments:
    #    print "issue: ", str(key)
    #    print "comments: "
    #    for c in issue_comments[key]:
    #        print c
    #        print "\n"

    print "FINISHED GRABBING COMMENTS!"
    
