# coding:utf-8
import numpy
import cv2

from matplotlib import pyplot as plt


def img_threshold(img, x, y):
    """
    """
    def get_pixel(ox, oy, default=0):
        """
        """
        try:
            return img[ox][oy]
        except Exception, e:
            return default
        
    center = img[x][y]
    out = []
    #求出局部二元模式序列
    for i in [get_pixel(x-1, y-1), get_pixel(x, y-1), get_pixel(x+1, y-1),
            get_pixel(x+1, y), get_pixel(x+1, y+1), get_pixel(x, y+1),
            get_pixel(x-1, y+1), get_pixel(x-1, y)]:
        out.append(1) if i > center else out.append(0)
    uFlag = 0
    #计算0/1切换的次数
    if (out[0] != out[7]):
    	uFlag += 1
    for j in range(len(out)-1):
    	if (out[j] != out[j+1]):
            uFlag += 1
   	#如果切换次数>2，返回9
    if (uFlag > 2):
    	return 9
    #不然的话就返回1的数目
    lbp = 0
    for i in out:
    	lbp += i
    return lbp

img = cv2.imread('test.jpg', 0)
result_img = cv2.imread('test.jpg', 0)
result=[0,0,0,0,0,0,0,0,0,0]
for x in range(len(img)):
    for y in range(len(img[0])):
    	index = img_threshold(img, x, y)
    	result[index] += 1
        # out = img_threshold(img, x, y)
        # res = 0
        # for index, o in enumerate(out):
        #     res += weights[index] * o
        # result_img.itemset((x, y), res)

# cv2.imwrite('threshold_lena.jpg', result_img)
# cv2.imshow('image', img)
# cv2.imshow('thresholded image', result_img)

#hist,bins = numpy.histogram(img.flatten(),256,[0,256])

#cdf = hist.cumsum()
#cdf_normalized = cdf * hist.max()/ cdf.max()

#plt.plot(cdf_normalized, color = 'b')
plt.plot(result, color = 'b')
plt.hist(result, 10,[0, 10], color = 'r')
plt.xlim([0, 10])
plt.legend(('cdf','histogram'), loc = 'upper left')
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()
