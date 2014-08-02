# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if not head:
            return False

        step1 = head
        step2 = head
        while True:
            step2 = step2.next
            if not step2:
                return False
            step2 = step2.next
            if not step2:
                return False
            step1 = step1.next
            if step1.val == step2.val:
                return True

def makeList(dataList, pos):
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
    if pos == -1:
        return head

    target = head
    for i in xrange(pos-1):
        target = target.next
    tail.next = target
    return head

if __name__ == '__main__':
    s = Solution()

    print s.hasCycle(None)
    print s.hasCycle(makeList([1,2,3,4,5], -1))
    print s.hasCycle(makeList([1,2,3,4,5,6], 3))
