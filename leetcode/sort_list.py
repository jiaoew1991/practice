class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    def lengthList(self, head):
        index = head
        length = 0
        while index:
            length += 1
            index = index.next
        return length
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        newHead = None
        while head:
            if not newHead:
                newHead, head = ListNode(head.val), head.next
                continue
            node = ListNode(head.val)
            if newHead.val > node.val:
                newHead, newHead.next = node, newHead
                continue
            index = newHead
            nextIndex = index.next
            while index:
                if not nextIndex:
                    index.next = node
                    break
                if node.val < nextIndex.val:
                    index.next, node.next = node, nextIndex
                    #index, nextIndex = nextIndex, newindex.next
                    break
                index, nextIndex = nextIndex, nextIndex.next
            head = head.next
        return newHead
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        if not head:
            return head
        listLen = self.lengthList(head)
        head = self.sortListImpl(head, listLen)
        return head

    def sortListImpl(self, head, length):
        if length == 1:
            return head

        halfLength = int(length/2)
        tail = head
        for i in range(halfLength-1):
            tail = tail.next
        midHead = tail.next
        tail.next = None
        #print "before: head:", self.printList(head), " midHead:", self.printList(midHead)

        fIndex = self.sortListImpl(head, halfLength)
        sIndex = self.sortListImpl(midHead, length - halfLength)
        if fIndex.val >= sIndex.val:
            fIndex, sIndex = sIndex, fIndex
        #print "merge, fIndex:", self.printList(fIndex), "sIndex:", self.printList(sIndex)
        head = fIndex
        nextfIndex = fIndex.next
        while fIndex and sIndex:
            if nextfIndex:
                if nextfIndex.val > sIndex.val:
                    fIndex.next, sIndex =sIndex, nextfIndex
                    fIndex = fIndex.next
                    nextfIndex = fIndex.next
                else:
                    fIndex, nextfIndex = nextfIndex, nextfIndex.next
            else:
                fIndex.next = sIndex
                break
        print "merge result:", self.printList(head)
        return head

    def makeList(self, dataList):
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
    def printList(self, head):
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

    head = s.makeList([2,4,1,5,3])
    print s.printList(head)
    head = s.insertionSortList(head)
    print s.printList(head)

    head = s.makeList(range(5000)[::-1])
    print s.printList(head)
    head = s.insertionSortList(head)
    print s.printList(head)
