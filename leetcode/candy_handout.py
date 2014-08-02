# coding: utf-8

class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        if len(ratings) == 0:
            return 0
        self.rec = 0
        rst = self.candyHelper(ratings)
        print rst
        return sum(rst)

    def candyHelper(self, ratings):
        """
        """
        if self.rec > 10:
            return ratings
        self.rec += 1

        if len(ratings) == 1:
            return [1]

        ratLen = len(ratings)
        bi = ratLen - 1
        while True:
            #print 'recursive,',self.rec,'bi',bi,'len',ratLen
            if bi <= 0:
                break
            if ratings[bi] > ratings[bi-1]:
                break
            bi -= 1
        rEnd = ratings[bi]

        print 'ratings', ratings
        if bi != 0:
            sub = self.candyHelper(ratings[:bi])


        if ratings[bi-1] < rEnd:
            sub.append(sub[-1] + 1)
        elif ratings[bi-1] > rEnd:
            #if sub[-1] > 1:
                #sub.append(sub[-1] - 1)
            #else:
                #bi = len(ratings) - 2
                #while True:
                    #if bi == 0:
                        #sub[bi] += 1
                        #break
                    #if ratings[bi] > ratings[bi-1]:
                        #break
                    #sub[bi] += 1
                    #bi -= 1
                #sub.append(1)
            sub += range(ratLen-bi, 0, -1)
        else:
            sub.append(sub[-1])

        return sub

if __name__ == '__main__':
    s = Solution()

    print s.candy([2,1,34,6,32,22,21,10,9,2,4,5])
    print s.candy([5,4,3,2,1])
    print s.candy([1,2,3,4,5])
