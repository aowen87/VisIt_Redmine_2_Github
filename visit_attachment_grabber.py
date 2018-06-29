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


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("start_ticket", type=int)
    parser.add_argument("stop_ticket", type=int)
    parser.add_argument("out_dir", type=str)
    args = parser.parse_args()
    out_dir = args.out_dir

    if not os.path.exists(out_dir):
        os.makedirs(out_dir)

    base  = "https://visitbugs.ornl.gov"

    for issue in range(start, stop): 
        html        = "%s/issues/%i" % (base, issue)
        raw_html    = simple_get(html)
        if raw_html == None:
            print "Ticket #%i was not found" % issue
        html_parser = BeautifulSoup(raw_html, 'html.parser')

        links = html_parser.find_all('a', {'class': 'icon icon-attachment'})
        for addr in links:
            ref   = addr['href']
            out_f = "%s/%i_%s" % (out_dir, issue, ref.split('/')[-1])
            url   = "%s%s" % (base, ref)
            urllib.urlretrieve(url, out_f)

    
