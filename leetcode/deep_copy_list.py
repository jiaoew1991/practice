# coding: utf-8

class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if not head:
            return None

        indexer = head
        cnt = 0
        while indexer:
            indexer.index = cnt
            cnt += 1
            indexer = indexer.next

        indexer = head
        a = []
        while indexer:
            a.append((indexer.label, indexer.random.index if indexer.random else None))
            indexer = indexer.next

        newHead = newTail = None
        labelNodeMap = {}
        for index, d in enumerate(a):
            tmp = RandomListNode(d[0])
            if not newTail:
                newHead = newTail = tmp
            else:
                newTail.next = tmp
                newTail = newTail.next
            labelNodeMap[index] = tmp

        indexer = newHead
        for d in a:
            #print d[1], 'indexer', indexer.label
            if d[1] != None:
                tNode = labelNodeMap[d[1]]
                indexer.random = tNode
            indexer = indexer.next

        return newHead
        
def makeList(dataList):
    """
    """
    head = tail = None
    for d in dataList:
        tmp = RandomListNode(d[0])
        if not tail:
            head = tail = tmp
        else:
            tail.next = tmp
            tail = tail.next

    indexer = head
    for d in dataList:
        if len(d) > 1 and d[1]:
            tmp = head
            while tmp:
                if tmp.label == d[1]:
                    indexer.random = tmp
                    break
                tmp = tmp.next
        indexer = indexer.next
    return head

def printList(head):
    """
    """
    index = head
    a = []
    while(index):
        a.append({ 'abel': index.label,
            'random': index.random.label if index.random else None })
        index = index.next
    return a

if __name__ == '__main__':
    s = Solution()

    #print s.copyRandomList(None)
    #print printList(s.copyRandomList(makeList([1,2,3,4,5])))
    #print printList(s.copyRandomList(makeList([1,2,3,4,5,6])))
    #print printList(makeList([(1, 3),(2, None),(3, None),(4, 1),(5, 2)]))
    print printList(s.copyRandomList(makeList([(1, 3),(2, None),(3, None),(4, 1),(5, 2)])))
