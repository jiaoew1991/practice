# coding: utf-8

import os
import lbp_riu
import threading
import multiprocessing as mp

output_lock = mp.Lock()
feature_queue = mp.Queue()
count = 0
MAX_FILE_NUMBER = 0

def generate_thread(name, label, queue):
    global count, MAX_FILE_NUMBER
    output_file = open("thread_%s_%s"%(name,label), "w")
    while (count >= MAX_FILE_NUMBER):
        print 'job ', name
        f = queue.get()
        dimension = lbp_riu.lib_riu(f, 8, 1)
        dimension += lbp_riu.lib_riu(f, 16, 2)
        dimension += lbp_riu.lib_riu(f, 24, 3)
        dimension += lbp_riu.lib_riu(f, 24, 4)
        line = format_output(enumerate(dimension), label)
        output_file.write(line)
        with output_lock:
            count += 1
            # if count > 300:
            #     break
            print count, f
            
    count = 0
    output_file.close()
    
def format_output(index_value, label):
    """
    index_value: list of (index,value) pair
    label: eg '+1' or something else
    """
    result = label+' ' + ' '.join([str(i)+':'+str(v) for i,v in index_value]) + '\n'
    return result

def generate_datafile(image_dir, label):
    """
    """
    global MAX_FILE_NUMBER
    source_files = [os.path.join(image_dir, f) for f in os.listdir(image_dir)]
    MAX_FILE_NUMBER = len(source_files)
    threads = []
    for i in range(4):
        worker = mp.Process(target=generate_thread, args=(i, label, feature_queue))
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
    feature_queue.join()

if __name__ == '__main__':
    # generate_datafile('../recaptured image/origin_A', '+1')
    generate_datafile('../recaptured image/recap_A', '-1')
