import sys
import os

exts = ['.cpp', '.h']
include_dir = ['common', 'data_structure', 'recursive']
def read_line_count(fname):
    count = 0
    for file_line in open(fname).xreadlines():
        count += 1
    return count

if __name__ == '__main__':

    count = 0
    fcount = 0
    for root,dirs,files in os.walk(os.getcwd()):
        for f in files:
            # Check the sub directorys
            fname = (root + '/'+ f).lower()
            try:
                ext = f[f.rindex('.'):]
                if(exts.index(ext) >= 0):
                    fcount += 1
                    c = read_line_count(fname)
                    count += c
            except:
                pass

    print 'file count:%d' % fcount
    print 'count:%d' % count
