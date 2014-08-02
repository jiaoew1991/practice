class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        start = 0
        end = len(A) - 1
        while True:
            p = self._partion(A, start, end)
            print 'arr,p', A, p
            if A[p] != A[p+1]:
                return A[p]
            elif p % 2 == 0:
                start = p
            else:
                end = p - 1

    def _partion(self, arr, start, end):
        """
        """
        print arr, start, end
        comp = arr[start]
        i = start
        j = end
        index = start 
        while index <= end:
            if arr[index] < comp:
                arr[index], arr[i] = arr[i], arr[index]
                i += 1
                index += 1
            elif arr[index] > comp:
                arr[index], arr[j] = arr[j], arr[index]
                j -= 1
            else:
                index += 1
        return i

if __name__ == '__main__':
    s = Solution()

    #print s.singleNumber([1,0,1])
    #print s.singleNumber([3,4,2,1,6,1,4,3,2,9,6])
    print s.singleNumber([17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6])
