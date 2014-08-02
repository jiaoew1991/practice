# coding:utf-8

class Solution:
    """
    """
    def reverseWords(self, s):
        """
        """
        rs = s.strip()[::-1]
        words = rs.split(' ')
        print words
        results = []
        for w in words:
            sw = w[::-1]
            if len(sw) > 0:
                results.append(sw)
        return ' '.join(results)

if __name__ == '__main__':
    s = Solution()
    print s.reverseWords('   a   b ')
