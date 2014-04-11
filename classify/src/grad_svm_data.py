# coding: utf-8

import os
import surface_grad
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
        dimension = surface_grad.grad(f)
        with output_lock:
            count += 1
            print count, f
            line = format_output(enumerate(dimension), label)
            output_file.write(line)
            output_file.flush()
    
def format_output(index_value, label):
    """
    index_value: list of (index,value) pair
    label: eg '+1' or something else
    """
    result = label+' ' + ' '.join([str(i+1)+':'+str(v) for i,v in index_value]) + '\n'
    return result

def generate_datafile(image_dir, label):
    """
    """
    fsvm = open('svm_' + label, 'w')
    source_files = [os.path.join(image_dir, f) for f in os.listdir(image_dir)]
    threads = []
    for i in range(4):
        worker = mp.Process(target=generate_thread, args=(i, fsvm, label, feature_queue))
        worker.start()
        threads.append(worker)

    for f in source_files:
        feature_queue.put(f)
    for t in threads:
        t.join()
    fsvm.close()

if __name__ == '__main__':
    generate_datafile('../test', '+1')
