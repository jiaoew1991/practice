# coding: utf-8

import pywt
import numpy
import cv2
import math

def wavelet(img_src):
    """
    """
    image = cv2.imread(img_src)
    haar = pywt.Wavelet('haar')
    blue, green, red = cv2.split(image)
    result = []
    for index, channel in enumerate([blue, green, red]):
        cA3, (cH3, cV3, cD3), (cH2, cV2, cD2), (cH1, cV1, cD1) = pywt.wavedec2(channel, haar, level = 3)
        for c in [cH3, cV3, cD3, cH2, cV2, cD2, cH1, cV1, cD1]:
            m = numpy.mean(c)
            s = numpy.std(c)
            result.append(m)
            result.append(s)
    return result

if __name__ == '__main__':
    res = wavelet('../test/im11_tc.jpg')
    print res, len(res)
