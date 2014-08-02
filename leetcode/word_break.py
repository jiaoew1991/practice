#coding: utf-8

class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dic):
        tmp = ''.join(dic)
        for c in s:
            if tmp.find(c) == -1:
                return False
        return self.wordBreakHelper(s, dic)

    def wordBreakHelper(self, s, dic):
        for d in dic:
            if len(d) < len(s):
                if s[:len(d)] == d and self.wordBreakHelper(s[len(d):], dic):
                    return True
            elif d == s:
                return True
        return False

if __name__ == '__main__':
    s = Solution()

    print s.wordBreak('nihao', ['askj', 'qwe;', 'ni', 'n', 'wkeqj', 'zkxcjv', 'qioweu', 'ha', 'ih', 'ao'])
    print s.wordBreak('nihao', ['askj', 'qwe;', 'wkeqj', 'zkxcjv', 'qioweu', 'hao', 'iha', 'oh'])
    print s.wordBreak('aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab', ['a','aa','aaa','aaaa','aaaaa','aaaaaa','aaaaaaa','aaaaaaaa','aaaaaaaaa','aaaaaaaaaa'])
    print s.wordBreak('cars', ['car','ca','rs'])
