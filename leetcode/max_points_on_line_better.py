# Definition for a point
import math

class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
    def equal(self, another):
        return self.x == another.x and self.y == another.y

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        maxResult = 0
        pointLen = len(points)
        if pointLen <= 2:
            return pointLen

        for i in range(pointLen):
            pt = points[i]
            slopeDict = {}
            slopeDict.clear()
            equalSum = 0
            for j in range(i+1, pointLen):
                opt = points[j]
                dx, dy = pt.x-opt.x, pt.y-opt.y
                if dx == 0 and dy == 0:
                    equalSum += 1
                slopeKey = "inf" if dx == 0 else float(dy) / dx
                if slopeKey in slopeDict:
                    slopeDict[slopeKey] += 1
                else:
                    slopeDict[slopeKey] = 2
            for key,value in slopeDict.items():
                if key != "inf":
                    value += equalSum
                maxResult = maxResult if maxResult > value else value
        return maxResult


if __name__ == '__main__':
    s = Solution()

    import time
    print time.time()
    print s.maxPoints([Point(1,1),Point(1,1),Point(2,3)])
    print s.maxPoints([Point(2,3), Point(3,4), Point(4,5), Point(4,4), Point(5,8), Point(8,8), Point(5,4)])
    print time.time()
    print s.maxPoints([Point(40,-23),Point(9,138),Point(429,115),Point(50,-17),Point(-3,80),Point(-10,33),
        Point(5,-21),Point(-3,80),Point(-6,-65),Point(-18,26),Point(-6,-65),Point(5,72),Point(0,77),Point(-9,86),
        Point(10,-2),Point(-8,85),Point(21,130),Point(18,-6),Point(-18,26),Point(-1,-15),Point(10,-2),Point(8,69),
        Point(-4,63),Point(0,3),Point(-4,40),Point(-7,84),Point(-8,7),Point(30,154),Point(16,-5),Point(6,90),
        Point(18,-6),Point(5,77),Point(-4,77),Point(7,-13),Point(-1,-45),Point(16,-5),Point(-9,86),Point(-16,11),
        Point(-7,84),Point(1,76),Point(3,77),Point(10,67),Point(1,-37),Point(-10,-81),Point(4,-11),Point(-20,13),
        Point(-10,77),Point(6,-17),Point(-27,2),Point(-10,-81),Point(10,-1),Point(-9,1),Point(-8,43),Point(2,2),
        Point(2,-21),Point(3,82),Point(8,-1),Point(10,-1),Point(-9,1),Point(-12,42),Point(16,-5),Point(-5,-61),
        Point(20,-7),Point(9,-35),Point(10,6),Point(12,106),Point(5,-21),Point(-5,82),Point(6,71),Point(-15,34),
        Point(-10,87),Point(-14,-12),Point(12,106),Point(-5,82),Point(-46,-45),Point(-4,63),Point(16,-5),
        Point(4,1),Point(-3,-53),Point(0,-17),Point(9,98),Point(-18,26),Point(-9,86),Point(2,77),Point(-2,-49),
        Point(1,76),Point(-3,-38),Point(-8,7),Point(-17,-37),Point(5,72),Point(10,-37),Point(-4,-57),Point(-3,-53),
        Point(3,74),Point(-3,-11),Point(-8,7),Point(1,88),Point(-12,42),Point(1,-37),Point(2,77),Point(-6,77),
        Point(5,72),Point(-4,-57),Point(-18,-33),Point(-12,42),Point(-9,86),Point(2,77),Point(-8,77),Point(-3,77),
        Point(9,-42),Point(16,41),Point(-29,-37),Point(0,-41),Point(-21,18),Point(-27,-34),Point(0,77),Point(3,74),
        Point(-7,-69),Point(-21,18),Point(27,146),Point(-20,13),Point(21,130),Point(-6,-65),Point(14,-4),Point(0,3),
        Point(9,-5),Point(6,-29),Point(-2,73),Point(-1,-15),Point(1,76),Point(-4,77),Point(6,-29)])
    print time.time()
    print s.maxPoints([Point(-240,-657),Point(-27,-188),Point(-616,-247),Point(-264,-311),Point(-352,-393),Point(-270,-748),Point(3,4),Point(-308,-87),
        Point(150,526),Point(0,-13),Point(-7,-40),Point(-3,-10),Point(-531,-892),Point(-88,-147),Point(4,-3),Point(-873,-555),Point(-582,-360),Point(-539,-207),
        Point(-118,-206),Point(970,680),Point(-231,-47),Point(352,263),Point(510,143),Point(295,480),Point(-590,-990),Point(-236,-402),Point(308,233),
        Point(-60,-111),Point(462,313),Point(-270,-748),Point(-352,-393),Point(-35,-148),Point(-7,-40),Point(440,345),Point(388,290),Point(270,890),Point(10,-7),
        Point(60,253),Point(-531,-892),Point(388,290),Point(-388,-230),Point(340,85),Point(0,-13),Point(770,473),Point(0,73),Point(873,615),Point(-42,-175),
        Point(-6,-8),Point(49,176),Point(308,222),Point(170,27),Point(-485,-295),Point(170,27),Point(510,143),Point(-18,-156),Point(-63,-316),Point(-28,-121),
        Point(396,304),Point(472,774),Point(-14,-67),Point(-5,7),Point(-485,-295),Point(118,186),Point(-154,-7),Point(-7,-40),Point(-97,-35),Point(4,-9),
        Point(-18,-156),Point(0,-31),Point(-9,-124),Point(-300,-839),Point(-308,-352),Point(-425,-176),Point(-194,-100),Point(873,615),Point(413,676),
        Point(-90,-202),Point(220,140),Point(77,113),Point(-236,-402),Point(-9,-124),Point(63,230),Point(-255,-118),Point(472,774),Point(-56,-229),
        Point(90,228),Point(3,-8),Point(81,196),Point(970,680),Point(485,355),Point(-354,-598),Point(-385,-127),Point(-2,7),Point(531,872),Point(-680,-263),
        Point(-21,-94),Point(-118,-206),Point(616,393),Point(291,225),Point(-240,-657),Point(-5,-4),Point(1,-2),Point(485,355),Point(231,193),Point(-88,-147),
        Point(-291,-165),Point(-176,-229),Point(154,153),Point(-970,-620),Point(-77,33),Point(-60,-111),Point(30,162),Point(-18,-156),Point(425,114),
        Point(-177,-304),Point(-21,-94),Point(-10,9),Point(-352,-393),Point(154,153),Point(-220,-270),Point(44,-24),Point(-291,-165),Point(0,-31),Point(240,799),
        Point(-5,-9),Point(-70,-283),Point(-176,-229),Point(3,8),Point(-679,-425),Point(-385,-127),Point(396,304),Point(-308,-352),Point(-595,-234),
        Point(42,149),Point(-220,-270),Point(385,273),Point(-308,-87),Point(-54,-284),Point(680,201),Point(-154,-7),Point(-440,-475),Point(-531,-892),
        Point(-42,-175),Point(770,473),Point(118,186),Point(-385,-127),Point(154,153),Point(56,203),Point(-616,-247)])
    print time.time()
    print s.maxPoints([
        Point(29,87),Point(145,227),Point(400,84),Point(800,179),Point(60,950),Point(560,122),Point(-6,5),
        Point(-87,-53),Point(-64,-118),Point(-204,-388),Point(720,160),Point(-232,-228),Point(-72,-135),Point(-102,-163),
        Point(-68,-88),Point(-116,-95),Point(-34,-13),Point(170,437),Point(40,103),Point(0,-38),Point(-10,-7),Point(-36,-114),
        Point(238,587),Point(-340,-140),Point(-7,2),Point(36,586),Point(60,950),Point(-42,-597),Point(-4,-6),Point(0,18),Point(36,586),
        Point(18,0),Point(-720,-182),Point(240,46),Point(5,-6),Point(261,367),Point(-203,-193),Point(240,46),Point(400,84),
        Point(72,114),Point(0,62),Point(-42,-597),Point(-170,-76),Point(-174,-158),Point(68,212),Point(-480,-125),Point(5,-6),
        Point(0,-38),Point(174,262),Point(34,137),Point(-232,-187),Point(-232,-228),Point(232,332),Point(-64,-118),Point(-240,-68),
        Point(272,662),Point(-40,-67),Point(203,158),Point(-203,-164),Point(272,662),Point(56,137),Point(4,-1),Point(-18,-233),
        Point(240,46),Point(-3,2),Point(640,141),Point(-480,-125),Point(-29,17),Point(-64,-118),Point(800,179),Point(-56,-101),
        Point(36,586),Point(-64,-118),Point(-87,-53),Point(-29,17),Point(320,65),Point(7,5),Point(40,103),Point(136,362),
        Point(-320,-87),Point(-5,5),Point(-340,-688),Point(-232,-228),Point(9,1),Point(-27,-95),Point(7,-5),Point(58,122),
        Point(48,120),Point(8,35),Point(-272,-538),Point(34,137),Point(-800,-201),Point(-68,-88),Point(29,87),Point(160,27),
        Point(72,171),Point(261,367),Point(-56,-101),Point(-9,-2),Point(0,52),Point(-6,-7),Point(170,437),Point(-261,-210),
        Point(-48,-84),Point(-63,-171),Point(-24,-33),Point(-68,-88),Point(-204,-388),Point(40,103),Point(34,137),
        Point(-204,-388),Point(-400,-106)])
    print time.time()

