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
    for i in [get_pixel(x-1, y-1), get_pixel(x, y-1), get_pixel(x+1, y-1),
            get_pixel(x+1, y), get_pixel(x+1, y+1), get_pixel(x, y+1),
            get_pixel(x-1, y+1), get_pixel(x-1, y)]:
        out.append(1) if i > center else out.append(0)
    return out

img = cv2.imread('test.jpg', 0)
result_img = cv2.imread('test.jpg', 0)
weights = [1, 2, 4, 8, 16, 32, 64, 128]
for x in range(len(img)):
    for y in range(len(img[0])):
        out = img_threshold(img, x, y)
        res = 0
        for index, o in enumerate(out):
            res += weights[index] * o
        result_img.itemset((x, y), res)

cv2.imwrite('threshold_lena.jpg', result_img)
cv2.imshow('image', img)
cv2.imshow('thresholded image', result_img)

hist,bins = numpy.histogram(img.flatten(),256,[0,256])

cdf = hist.cumsum()
cdf_normalized = cdf * hist.max()/ cdf.max()

plt.plot(cdf_normalized, color = 'b')
plt.hist(result_img.flatten(),256,[0,256], color = 'r')
plt.xlim([0,256])
plt.legend(('cdf','histogram'), loc = 'upper left')
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()
