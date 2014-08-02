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
    def preorderTraversal(self, root):
        if not root:
            return []
        result = []
        waitingList = [root]
        while len(waitingList):
            node = waitingList.pop()
            if node.right:
                waitingList.append(node.right)
            if node.left:
                waitingList.append(node.left)
            result.append(node.val)
        return result

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

    print s.preorderTraversal(buildTree([1,2]))
    print s.preorderTraversal(buildTree([6,2,1,4,3,5,7,9,8]))
    print s.preorderTraversal(buildTree([4,2,3,6,5]))
    print s.preorderTraversal(buildTree([8,43,2,32,6,16,9,10,4,3,11,33]))
