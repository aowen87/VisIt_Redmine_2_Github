import os
import glob
import argparse
from shutil import copyfile



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("in_path", type=str)
    parser.add_argument("out_path", type=str)
    args = parser.parse_args() 

    in_path  = args.in_path 
    out_path = args.out_path 

    if not os.path.isdir(out_path):
        os.mkdir(out_path)

    max_len = -1
    for f_name in os.listdir(in_path):
        t_num = f_name.split('_')[0]
        new_len = len(t_num)
        max_len = new_len if new_len > max_len else max_len
            
    for f_name in os.listdir(in_path):
        t_num    = f_name.split('_')[0]
        no_t_num = '_'.join(f_name.split('_')[1:])
        t_len    = len(t_num)

        pad_cnt     = max_len - t_len
        padded_num  = '0' * pad_cnt
        padded_num += t_num

        padded_f_name = padded_num + '_' + no_t_num
        src_f = os.path.join(in_path, f_name)
        dst_f = os.path.join(out_path, padded_f_name)
        copyfile(src_f, dst_f)
        #print padded_num


    
