class Solution:

    OPERATORS = ['+', '-', '*', '/']

    def evalRPN(self, tokens):
        values = []
        for token in tokens:
            if token in self.OPERATORS:
                right =values.pop()
                left =values.pop()
                if token == '+':
                    values.append(left + right)
                elif token == '-':
                    values.append(left - right)
                elif token == '*':
                    values.append(left * right)
                elif token == '/':
                    values.append(int(float(left) / right))
            else:
                values.append(int(token))
            print values
        return values[0]

if __name__ == '__main__':
    s = Solution()
    #print s.evalRPN( ["2", "1", "+", "3", "*"] )
    #print s.evalRPN(["4", "13", "5", "/", "+"])
    print s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])

