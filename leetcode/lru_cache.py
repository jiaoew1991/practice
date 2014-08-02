# coding: utf-8

class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.usedKeys = []
        self.cache = {}
        
    # @return an integer
    def get(self, key):
        value = self.cache.get(key, -1)
        if value != -1:
            try:
                self.usedKeys.remove(key)
            except Exception, e:
                pass
            self.usedKeys.append(key)
        return value

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        self.cache[key] = value
        if len(self.cache) > self.capacity and len(self.usedKeys) > 0:
            usedKey = self.usedKeys.pop()
            self.cache.pop(usedKey)

    def size(self):
        return len(self.cache)

def case1():
    """
    """
    lru = LRUCache(2)
    lru.set(2, 1)
    lru.set(1, 1)
    lru.set(2, 3)
    lru.set(4, 1)
    print '1: ', lru.get(1)
    print '4: ', lru.get(4)

def case2():
    """
    """
    lru = LRUCache(10)
    lru.set(10,13)
    lru.set(3,17)
    lru.set(6,11)
    lru.set(10,5)
    lru.set(9,10)
    print '13', lru.get(13)
    lru.set(2,19)
    print '2', lru.get(2)
    print '3', lru.get(3)
    lru.set(5,25)
    print '8', lru.get(8)
    lru.set(9,22)
    lru.set(5,5)
    lru.set(1,30)
    print '11', lru.get(11)
    lru.set(9,12)
    print '7', lru.get(7)
    print '5', lru.get(5)
    print '8', lru.get(8)
    print '9', lru.get(9)
    lru.set(4,30)
    lru.set(9,3)
    print '9', lru.get(9)
    print '10', lru.get(10)
    print '10', lru.get(10)
    lru.set(6,14)
    lru.set(3,1)
    print '3', lru.get(3)
    lru.set(10,11)
    print '8', lru.get(8)
    lru.set(2,14)
    print '1', lru.get(1)
    print '5', lru.get(5)
    print '4', lru.get(4)
    lru.set(11,4)
    lru.set(12,24)
    lru.set(5,18)
    print '13', lru.get(13)
    lru.set(7,23)
    print '8', lru.get(8)
    print '12', lru.get(12)
    lru.set(3,27)
    lru.set(2,12)
    print '5', lru.get(5)
    lru.set(2,9)
    lru.set(13,4)
    lru.set(8,18)
    lru.set(1,7)
    print '6', lru.get(6)
    lru.set(9,29)
    lru.set(8,21)
    print '5', lru.get(5)
    lru.set(6,30)
    lru.set(1,12)
    print '10', lru.get(10)
    lru.set(4,15)
    lru.set(7,22)
    lru.set(11,26)
    lru.set(8,17)
    lru.set(9,29)
    print '5', lru.get(5)
    lru.set(3,4)
    lru.set(11,30)
    print '12', lru.get(12)
    lru.set(4,29)
    print '3', lru.get(3)
    print '9', lru.get(9)
    print '6', lru.get(6)
    lru.set(3,4)
    print '1', lru.get(1)
    print '10', lru.get(10)
    lru.set(3,29)
    lru.set(10,28)
    lru.set(1,20)
    lru.set(11,13)
    print '3', lru.get(3)
    lru.set(3,12)
    lru.set(3,8)
    lru.set(10,9)
    lru.set(3,26)
    print '8', lru.get(8)
    print '7', lru.get(7)
    print '5', lru.get(5)
    lru.set(13,17)
    lru.set(2,27)
    lru.set(11,15)
    print '12', lru.get(12)
    lru.set(9,19)
    lru.set(2,15)
    lru.set(3,16)
    print '1', lru.get(1)
    lru.set(12,17)
    lru.set(9,1)
    lru.set(6,19)
    print '4', lru.get(4)
    print '5', lru.get(5)
    print '5', lru.get(5)
    lru.set(8,1)
    lru.set(11,7)
    lru.set(5,2)
    lru.set(9,28)
    print '1', lru.get(1)
    lru.set(2,2)
    lru.set(7,4)
    lru.set(4,22)
    lru.set(7,24)
    lru.set(9,26)
    lru.set(13,28)
    lru.set(11,26)

def case3():
    """
    """
    lru = LRUCache(2)
    lru.set(2, 1)
    lru.set(1, 1)
    print '2: ', lru.get(2)
    lru.set(4, 1)
    print '1: ', lru.get(1)
    print '2: ', lru.get(2)
    
    

if __name__ == '__main__':
    case3()
    #lru = LRUCache(5)

    #lru.set('a', 4)
    #print 'a', lru.get('a')
    #lru.set('a', 9)
    #print 'size', lru.size()
    #lru.set('b', 6)
    #lru.set('c', 3)
    #lru.set('d', 2)
    #print 'c', lru.get('c')
    #lru.set('f', 0)
    #print 'a', lru.get('a')
    #lru.set('g', 10)
    #print 'c', lru.get('c')
    #print 'g', lru.get('g')
    #print 'a', lru.get('a')
    #lru.set('f', 23)
    #print 'f', lru.get('f')
    #lru.set('h', 32)
    #print 'h', lru.get('h')
    #print 'f', lru.get('f')
