#coding: utf-8

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
        if not head:
            return None
        listLen = self.length(head)
        result = head
        cnt = 0

        pMiddle = head
        preM = None
        while cnt < (listLen+1) / 2:
            pMiddle = pMiddle.next
            cnt += 1
            if not preM:
                preM = head
                continue
            preM = preM.next
        
        preM.next = None
        pMiddle = self.reverseList(pMiddle)

        pLeft, pRight = head, pMiddle
        while pLeft and pRight:
            a, b = pLeft.next, pRight.next
            pLeft.next = pRight
            pRight.next = a
            pLeft, pRight = a, b

        return head
            
    def reverseList(self, head):
        """
        """
        result = None
        indexer = head

        rPrev = None
        while indexer:
            rTmp = indexer
            indexer = indexer.next
            rTmp.next = rPrev
            rPrev = rTmp

        printList(rPrev)
        return rPrev

    def length(self, head):
        """
        """
        tmp = head
        counter = 0
        while tmp:
            counter += 1
            tmp = tmp.next
        return counter
        

def makeList(dataList):
    """
    """
    head = tail = None
    for d in dataList:
        tmp = ListNode(d)
        if not tail:
            head = tail = tmp
        else:
            tail.next = tmp
            tail = tail.next
    return head
def printList(head):
    """
    """
    index = head
    a = []
    while(index):
        a.append(index.val)
        index = index.next
    return a

if __name__ == '__main__':
    s = Solution()

    print s.reorderList(None)
    print printList(s.reorderList(makeList([1,2,3,4,5])))
    print printList(s.reorderList(makeList([1,2,3,4,5,6])))
