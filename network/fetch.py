# coding: utf-8

import httplib, urllib2
import HTMLParser
import threading
from Queue import Queue
import os

class DataParser(HTMLParser.HTMLParser):

    imagename = []
    image_url = []
    category = []
    
    def handle_data(self, data):
        if data.startswith('ImageName'):
            self.imagename.append(data.strip())
        elif data.find('URL') != -1:
            self.image_url.append(data.strip())
        elif data.find('Category') != -1:
            self.category.append(data.strip())

    def format_result(self):
        """
        """
        result = []
        for i, name in enumerate(self.imagename):
            url = self.image_url[i]
            c = self.category[i]
            result.append((name.split('=')[1].strip(), url.split('=')[1], c.split('=')[1].strip()))
        return result

count_lock = threading.Lock()
count = 0
url_queue = Queue()

def fetcher(index, queue):
    global count, search_result
    while True:
        print 'threading: %d'%(index)
        url = queue.get()

        with count_lock:
            count += 1
            print 'number:', count, 'name:', url[0], 'remain:', float(count) / 800 * 100,'%'
            if count >= 800:
                print 'count over'
                break;

        dirname = url[2]
        if not os.path.exists('./' + dirname):
            os.mkdir(dirname)
        if os.path.exists(os.path.join(dirname, url[0])):
            print 'cached'
            continue
        try:
            image_data = urllib2.urlopen(url[1], timeout=5).read()
            f = open(os.path.join(dirname, url[0]), 'wb')
            f.write(image_data)
            f.close()
        except IOError, e:
            print e

threads = []
for i in range(10):
    worker = threading.Thread(target=fetcher, args=(i, url_queue))
    worker.setDaemon(True)
    worker.start()
    threads.append(worker)

f = open('source.html', 'r')
pagedata = f.read()
parser = DataParser()
parser.feed(pagedata)

search_result = parser.format_result()
for line in search_result:
    url_queue.put(line)

url_queue.join()
