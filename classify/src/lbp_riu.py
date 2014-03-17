# coding: utf-8
import numpy
import cv2

point_raidus = {
        '8_1': [(-1, 0), (0, -1), (1, -1), (1, 0),
                (1, 1), (0, 1), (-1, 1), (-1, 0)],
        '16_2': [(-2, 0), (-2 , 1), (-1, 1), (-1, 2),
                (0, 2), (1, 2), (1, 1), (1, 2), 
                (2, 0), (2 , 1), (1, -1), (1, -2),
                (0, -2), (-1, -2), (-1, -1), (-1, -2)],
        '24_3': [(-3, 0), (-3, 1), (-3, 2), (-2, 2), (-2, 3), (-1, 3), 
                (0, 3), (1, 3), (2, 3), (2, 2), (3, 2), (3, 1), 
                (3, 0), (3, -1), (3, -2), (2, -2), (2, -3), (1, -3), 
                (0, -3), (-1, -3), (-2, -3), (-2, -2), (-3, -2), (-3, -1)],
        '24_4': [(-4, 0), (-4, 1), (-3, 2), (-3, 3), (-2, 3), (-1, 4),
                (0, 4), (1, 4), (2, 3), (3, 3), (3, 2), (4, 1),
                (4, 0), (4, -1), (3, -2), (3, -3), (2, -3), (1, -4),
                (0, -4), (-1, -4), (-2, -3), (-3, -3), (-3, -2), (-4, -1)]
    }
def _img_threshold(img, x, y, point_list):
    """
    """
    def get_pixel(ox, oy, default=0):
        """
        """
        try:
            return img[ox][oy]
        except Exception, e:
            return default
        
    point_len = len(point_list)
    center = img[x][y]
    out = []
    #求出局部二元模式序列
    for dx, dy in point_list:
        out.append(1) if get_pixel(x+dx, y+dy) > center else out.append(0)
    uFlag = 0
    #计算0/1切换的次数
    uFlag += sum(1 for i in out if out[i] != out[(i+1)%point_len])

   	#如果切换次数>2，返回9
    #不然的话就返回1的数目
    lbp = sum(i for i in out)
    return point_len + 1 if uFlag > 2 else lbp

def lib_riu(img_src, p, r):
    """
    img_src: image's source file's path
    p: number of point
    r: radius 
    """
    img = cv2.imread(img_src, 0)
    result = [0] * (p+2)
    for x in range(len(img)):
        for y in range(len(img[0])):
            index = _img_threshold(img, x, y, point_raidus[str(p)+'_'+str(r)])
            result[index] += 1
    return result
    

if __name__ == '__main__':
    from time import strftime, gmtime
    print 'begin', strftime("%Y-%m-%d %H:%M:%S", gmtime())
    print lib_riu('../recaptured image/DatasetA/AcerB/Scenery-AcerB/PIC091110002.jpg', 8, 1)
    print '8 1 finished',strftime("%Y-%m-%d %H:%M:%S", gmtime())
    print lib_riu('../recaptured image/DatasetA/AcerB/Scenery-AcerB/PIC091110002.jpg', 16, 2)
    print '16 2 finished', strftime("%Y-%m-%d %H:%M:%S", gmtime())
    print lib_riu('../recaptured image/DatasetA/AcerB/Scenery-AcerB/PIC091110002.jpg', 24, 3)
    print '24 3 finished', strftime("%Y-%m-%d %H:%M:%S", gmtime())
    print lib_riu('../recaptured image/DatasetA/AcerB/Scenery-AcerB/PIC091110002.jpg', 24, 4)
    print '24 4 finished', strftime("%Y-%m-%d %H:%M:%S", gmtime())
