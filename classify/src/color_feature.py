#coding:utf-8
import cv2
import numpy, scipy, scipy.stats
import math

def _toarray(arr):
    """
    """
    return [item for inner in arr for item in inner]
    

def rgb_average(b, g, r):
    """
    """
    result = []
    for channel in [b, g, r]:
        result.append(numpy.mean(_toarray(channel)))
    
    return result

def rgb_pair(b, g, r):
    """
    """
    ba, ga, ra = _toarray(b), _toarray(g), _toarray(r)
    return [numpy.corrcoef(ra, ba)[0][1], numpy.corrcoef(ga, ra)[0][1], numpy.corrcoef(ba, ga)[0][1]]

def center(b, g, r):
    """
    """
    res = []
    for c in [b, g, r]:
        carray = _toarray(c)
        mess = [0] * 256
        for i in carray:
            mess[i - 1] += 1 if i > 0 else 0
            mess[i + 1] += 1 if i < 255 else 0
        res.append(numpy.median(mess) / (len(carray) - 1))
    return res

def energy(b, g, r):
    """
    """
    ba, ga, ra = _toarray(b), _toarray(g), _toarray(r)
    sumb, sumg, sumr = float(numpy.sum(ba)), float(numpy.sum(ga)), float(numpy.sum(ra))
    return [(sumg/sumb) ** 2, (sumg/sumr) ** 2, (sumb/sumr) ** 2]

def hsv_momnet(image):
    """
    """
    hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)
    h, s, v = cv2.split(hsv)
    res = []
    for c in [_toarray(h), _toarray(s), _toarray(v)]:
        scipy.stats.describe
        res += [numpy.mean(c), numpy.std(c), scipy.stats.skew(c)]
    return res

def all_features(image_src):
    """
    """
    image = cv2.imread(image_src)
    b, g, r = cv2.split(image)
    return rgb_average(b, g, r) + rgb_pair(b, g, r) + center(b, g, r) + energy(b, g, r) + hsv_momnet(image)
    

if __name__ == '__main__':
    print all_features('../test/im12_c.jpg')
