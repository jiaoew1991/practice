#coding: utf-8
import cv2
import math

ALPHA = 1 / 0.25

def grad(img_src, length = 8):
    """
    """
    # img = cv2.imread(img_src)
    # blue, green, red = cv2.split(img)
    # result = [0] * length * 3
    # for index, k in enumerate([blue, green, red]):
    #     for i in range(len(k) - 1):
    #         for j in range(len(k[0]) -1):
    #             ix = int(k[i][j]) - int(k[i+1][j])
    #             iy = int(k[i][j]) - int(k[i][j+1])
    #             detlaI = ix*ix + iy*iy
    #             gradi = math.sqrt(detlaI/(detlaI + ALPHA*ALPHA))
    #             value = int(gradi * length)
    #             result[index * length + value] += 1
    # total = sum(result)
    # result = [float(i) / total * 3 for i in result]
    # return result

    img = cv2.imread(img_src, 0)
    # blue, green, red = cv2.split(img)
    result = [0] * length
    # for index, k in enumerate([blue, green, red]):
    for i in range(len(img) - 1):
        for j in range(len(img[0]) -1):
            ix = int(img[i][j]) - int(img[i+1][j])
            iy = int(img[i][j]) - int(img[i][j+1])
            detlaI = ix*ix + iy*iy
            gradi = math.sqrt(detlaI/(detlaI + ALPHA*ALPHA))
            value = int(gradi * length)
            result[value] += 1
    total = sum(result)
    result = [float(i) / total for i in result]
    return result

if __name__ == '__main__':
    r = grad('1.jpg')
    f = open("1.txt", "w")
    f.write(str(r))
    f.close()
    
