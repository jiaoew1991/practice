#coding: utf-8

class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dic):
        self.allRst = []
        self.candidate = []
        self.originStr = s
        tmp = ''.join(dic)

        for c in s:
            if tmp.find(c) == -1:
                return []

        index = 0
        while self.wordBreakHelper(s, dic):
            #print index
            #if index > 2:
                #break
            index += 1

        result = []
        for rst in self.allRst:
            result.append(' '.join(rst))
        return result

    def wordBreakHelper(self, s, dic):
        for d in dic:
            if len(d) < len(s):
                if s[:len(d)] == d:
                    self.candidate.append(d)
                    rst = self.wordBreakHelper(s[len(d):], dic)
                    if not rst:
                        self.candidate.pop()
                    else:
                        return True
            elif d == s:
                self.candidate.append(d)
                if self.candidate in self.allRst:
                    self.candidate.pop()
                else:
                    self.allRst.append(self.candidate)
                    self.candidate = []
                    return True
        return False

if __name__ == '__main__':
    s = Solution()

    print s.wordBreak('nihao', ['askj', 'qwe;', 'ni', 'n', 'wkeqj', 'zkxcjv', 'qioweu', 'ha', 'ih', 'ao', 'o', 'hao'])
    print s.wordBreak('nihao', ['askj', 'qwe;', 'wkeqj', 'zkxcjv', 'qioweu', 'hao', 'iha', 'oh'])
    print s.wordBreak('aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab', ['a','aa','aaa','aaaa','aaaaa','aaaaaa','aaaaaaa','aaaaaaaa','aaaaaaaaa','aaaaaaaaaa'])
    print s.wordBreak('cars', ['car','ca','rs'])
    print s.wordBreak('catsanddog', ['cat', 'cats', 'and', 'sand', 'dog'])
