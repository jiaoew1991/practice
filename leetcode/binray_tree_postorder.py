#coding: utf-8

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:

    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        if not root:
            return []
        result = []
        waitingList = [root]
        while len(waitingList):
            node = waitingList.pop()
            if node.left:
                waitingList.append(node.left)
            if node.right:
                waitingList.append(node.right)
            result.append(node.val)
            #if not node.right or (node.right.val in result):
                #result.append(node.val)
                #if node.left:
                    #waitingList.append(node.left)
            #else:
                #waitingList.append(node)
                #waitingList.append(node.right)
        return result[::-1]

def buildTreeHelper(subRoot, value):
    if subRoot.val > value:
        if subRoot.left:
            buildTreeHelper(subRoot.left, value)
        else:
            subRoot.left = TreeNode(value)
    else:
        if subRoot.right:
            buildTreeHelper(subRoot.right, value)
        else:
            subRoot.right = TreeNode(value)

def buildTree(values):
    """
    """
    root = TreeNode(values[0])
    for value in values[1:]:
        buildTreeHelper(root, value)
    return root

if __name__ == '__main__':
    s = Solution()

    print s.postorderTraversal(buildTree([1,2]))
    print s.postorderTraversal(buildTree([4,2,3,6,5]))
    print s.postorderTraversal(buildTree([8,43,2,32,6,16,9,10,4,3,11,33]))
