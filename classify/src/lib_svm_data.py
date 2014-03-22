# coding: utf-8

import os
import lbp_riu
import threading
import multiprocessing as mp

output_lock = mp.Lock()
feature_queue = mp.Queue()
count = 0

def generate_thread(name, output_file, label, queue):
    global count
    while True:
        print 'job ', name
        f = queue.get()
        dimension = lbp_riu.lib_riu(f, 8, 1)
        dimension += lbp_riu.lib_riu(f, 16, 2)
        dimension += lbp_riu.lib_riu(f, 24, 3)
        dimension += lbp_riu.lib_riu(f, 24, 4)
        with output_lock:
            count += 1
            if count > 300:
                break
            print count, f
            line = format_output(enumerate(dimension), label)
            output_file.write(line)
    
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
    threads = []
    for i in range(4):
        worker = mp.Process(target=generate_thread, args=(i, fsvm, label, feature_queue))
        worker.start()
        threads.append(worker)

    for f in source_files:
        feature_queue.put(f)
        #dimension = lbp_riu.lib_riu(f, 8, 1)
        #dimension += lbp_riu.lib_riu(f, 16, 2)
        #dimension += lbp_riu.lib_riu(f, 24, 3)
        #dimension += lbp_riu.lib_riu(f, 24, 4)
        #line = format_output(enumerate(dimension), label)
        #print f, line
        #fsvm.write(line)
    for t in threads:
        t.join()
    fsvm.close()

if __name__ == '__main__':
    generate_datafile('../recaptured image/DatasetA/AcerB/Scenery-AcerB', '+1')
