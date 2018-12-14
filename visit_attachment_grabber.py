"""
Retrive all redmine attachments for visit tickets. 

@author: Alister Maguire 

"""

import os
import argparse
from bs4 import BeautifulSoup
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

        links = html_parser.find_all('a', {'class': 'icon icon-attachment'})
        for addr in links:
            ref   = addr['href']
            out_f = "%s/%i_%s" % (out_dir, issue, ref.split('/')[-1])
            url   = "%s%s" % (base, ref)
            urllib.urlretrieve(url, out_f)

    print "FINISHED GRABBING ATTACHMENTS!"
    
