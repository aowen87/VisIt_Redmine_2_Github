"""
Retrive all redmine attachments for visit tickets. 

@author: Alister Maguire 

Acknowledgements:
    Functions 'simple_get',  'is_good_response', and 'log_error' were
    all taken verbatim from 
    https://realpython.com/python-web-scraping-practical-introduction/
"""

from requests import get
import os
import argparse
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup
import urllib
import csv

def simple_get(url):
    """
    Attempts to get the content at `url` by making an HTTP GET request.
    If the content-type of response is some kind of HTML/XML, return the
    text content, otherwise return None.
    """
    try:
        with closing(get(url, stream=True)) as resp:
            if is_good_response(resp):
                return resp.content
            else:
                return None

    except RequestException as e:
        log_error('Error during requests to {0} : {1}'.format(url, str(e)))
        return None


def is_good_response(resp):
    """
    Returns True if the response seems to be HTML, False otherwise.
    """
    content_type = resp.headers['Content-Type'].lower()
    return (resp.status_code == 200 
            and content_type is not None 
            and content_type.find('html') > -1)


def log_error(e):
    """
    It is always a good idea to log errors. 
    This function just prints them, but you can
    make it do anything.
    """
    print(e)


def bf_find(parser, a, b, c):
    result = parser.find(a, {b: c})
    if result:
        return result.text
    return ""


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("start_ticket", type=int)
    parser.add_argument("stop_ticket", type=int)
    args = parser.parse_args()
    start   = args.start_ticket
    stop    = args.stop_ticket

    log = open("redmine_ticket_numbers.log", "w")

    base = "https://visitbugs.ornl.gov"

    with open('redmine_tickets.csv', mode='w') as out_csv:
        fields = ["Status", "Tracker", "Priority", "Subject", "Assigned to", 
                  "Category", "Target version", "Author", "Start", "Due date", 
                  "% Done", "Estimated time", "Created", "Updated", "Likelihood",
                  "Severity", "Found in Version", "Impact", "Expected Use",
                  "OS", "Support Group", "Description"]
        writer = csv.DictWriter(out_csv, fieldnames=fields)
        writer.writeheader()

        for issue in range(start, stop): 
            html        = "%s/issues/%i" % (base, issue)
            raw_html    = simple_get(html)
            if raw_html == None:
                print "Ticket #%i was not found" % issue
                continue
            log.write(str(issue))
            html_parser = BeautifulSoup(raw_html, 'html.parser')

            row_dict = {}

            title               = html_parser.find('title').text
            row_dict["Tracker"] = title.split("#")[0].split()[-1]
            row_dict["Subject"] = title.split(":", 1)[1].rsplit("-", 1)[-2]

            author_c            =  html_parser.find('p', {'class': 'author'})
            row_dict["Author"]  = ""
            row_dict["Created"] = ""
            row_dict["Updated"] = ""
            if author_c:
                row_dict["Author"]  = author_c.find('a').text
                date                = author_c.find_all('a', title=True)
                row_dict["Created"] = date[0]['title']
                if "Updated" in str(author_c):
                    row_dict["Updated"] = date[1]['title']
               
            row_dict["Status"]         = bf_find(html_parser, 'td', 'class', 'status')
            row_dict["Priority"]       = bf_find(html_parser, 'td', 'class', 'priority')
            row_dict["Assigned to"]    = bf_find(html_parser, 'td', 'class', 'assigned-to')
            row_dict["Category"]       = bf_find(html_parser, 'td', 'class', 'category')
            row_dict["Target version"] = bf_find(html_parser, 'td', 'class', 'fixed-version')
            row_dict["Start"]          = bf_find(html_parser, 'td', 'class', 'start-date') 
            row_dict["Due date"]       = bf_find(html_parser, 'td', 'class', 'due-date') 
            row_dict["% Done"]         = bf_find(html_parser, 'p', 'class', 'pourcent')
            row_dict["Estimated time"] = bf_find(html_parser, 'td', 'class', 'estimated-hours')

            row_dict["Likelihood"]       = ""
            row_dict["Severity"]         = ""
            row_dict["Found in Version"] = ""
            row_dict["Impact"]           = ""
            row_dict["Expected Use"]     = ""
            row_dict["OS"]               = ""
            row_dict["Support Group"]    = ""
            ths  = html_parser.find_all('th') 
            for th in ths:
                if 'Likelihood' in th.text:
                    row_dict["Likelihood"] = th.nextSibling.text
                if 'Severity' in th.text:
                    row_dict["Severity"] = th.nextSibling.text
                if 'Found in Version' in th.text:
                    row_dict["Found in Version"] = th.nextSibling.text
                if 'Impact' in th.text:
                    row_dict["Impact"] = th.nextSibling.text
                if 'Expected Use' in th.text:
                    row_dict["Expected Use"] = th.nextSibling.text
                if 'OS' in th.text:
                    row_dict["OS"] = th.nextSibling.text
                if 'Support Group' in th.text:
                    row_dict["Support Group"] = th.nextSibling.text

            row_dict["Description"] = ""
            paras = html_parser.find_all('p') 
            for para in paras:
                if para.text == "Description":
                    row_dict["Description"] = para.nextSibling.nextSibling.text
              
            #
            # Remove all non-ascii characters. 
            #
            for key in row_dict:
                value         = row_dict[key]
                row_dict[key] = [char for char in value if ord(char) < 128]

            writer.writerow(row_dict)


    print "FINISHED GRABBING ATTACHMENTS!"
    log.close()
    
