# coding: utf-8

import os
import lbp_riu

def format_output(index_value, label):
    """
    index_value: list of (index,value) pair
    label: eg '+1' or something else
    """
    result = label+' ' + ' '.join([str(i)+':'+str(v) for i,v in index_value]) + '\n'
    return result

def generate_datafile(image_dir, label, num=300):
    """
    """
    fsvm = open('svm_' + label, 'w')
    source_files = [os.path.join(image_dir, f) for f in os.listdir(image_dir)[:num]]
    for f in source_files:
        dimension = lbp_riu.lib_riu(f, 8, 1)
        dimension += lbp_riu.lib_riu(f, 16, 2)
        dimension += lbp_riu.lib_riu(f, 24, 3)
        dimension += lbp_riu.lib_riu(f, 24, 4)
        line = format_output(enumerate(dimension), label)
        print f, line
        fsvm.write(line)
    fsvm.close()

if __name__ == '__main__':
    generate_datafile('../recaptured image/DatasetA/AcerB/Scenery-AcerB', '+1')
