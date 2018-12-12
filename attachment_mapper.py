import os
import json
import shutil
import argparse


def map_red_to_git(red_dir, ticket_map):
    git_dir = "git_labeled_attachments"
    os.mkdir(git_dir)

    #
    # First, copy over the files to our destination. Then 
    # rename it. 
    #
    for red_fname in os.listdir(red_dir):
        red_fpath = os.path.join(red_dir, red_fname) 
        if os.path.isfile(red_fpath):
            shutil.copy(red_fpath, git_dir) 
            red_ticket, attach = red_fname.split("_", 1)
             
            if red_ticket not in ticket_map:
                print "ERROR: ticket %s not found!!!" % red_ticket
            else:
                git_ticket = ticket_map[red_ticket]
                git_fpath  = os.path.join(git_dir, git_ticket + '_' + attach)
                os.rename(os.path.join(git_dir, red_fname), git_fpath) 



if __name__ == "__main__":
    parser = argparse.ArgumentParser()    
    parser.add_argument("ticket_map", type=str, help="""json file mapping redmine ticket 
        numbers to github ticket numbers""")

    args       = parser.parse_args()
    ticket_map = {}
    
    with open(args.ticket_map, 'r') as json_f:
        ticket_map = json.load(json_f)

    map_red_to_git("attachments", ticket_map)


