import os
import glob
import argparse
from shutil import copyfile
from zipfile import *


#
# List of extensions that github accepts for
# issue attachments. 
#
VALID_GIT_EXTS = ['gif', 'jpeg', 'jpg',
                  'png', 'docx', 'gz', 
                  'log', 'pdf', 'pptx', 
                  'txt', 'xlsx', 'zip']



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("in_path", type=str)
    parser.add_argument("out_path", type=str)
    args = parser.parse_args() 

    in_path  = args.in_path 
    out_path = args.out_path 

    if not os.path.isdir(out_path):
        os.mkdir(out_path)

    do_copy = False
    if in_path != out_path:
        do_copy = True

    for f_name in os.listdir(in_path):
        ext      = f_name.split('.')[-1]
        src_file = os.path.join(in_path, f_name)
        dst_file = os.path.join(out_path, f_name)
        if do_copy:
            copyfile(src_file, dst_file)
        if ext.lower() not in VALID_GIT_EXTS:
            zip_dest = dst_file + '.zip'
            with ZipFile(zip_dest, 'w') as zf:
                zf.write(dst_file, f_name)
            os.remove(dst_file)
            
    


    
