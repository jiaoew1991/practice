# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        if not head:
            return None

        step1 = head
        step2 = head
        while True:
            step2 = step2.next
            if not step2:
                return None
            step2 = step2.next
            if not step2:
                return None
            step1 = step1.next
            if step1 == step2:
                break
        step2 = head
        while True:
            if step1 == step2:
                return step1
            step1, step2 = step1.next, step2.next
        
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

    print s.detectCycle(None)
    print s.detectCycle(makeList([1,2,3,4,5], -1))
    print s.detectCycle(makeList([1,2,3,4,5,6], 3)).val
