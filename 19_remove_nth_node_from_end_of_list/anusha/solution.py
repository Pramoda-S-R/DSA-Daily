from typing import Optional

class ListNode:
    def __init__(self, val=0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next


def node(head: ListNode):
    while head:
        print(head.val, "->", end=" ")
        head = head.next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        fast = slow = dummy
        for _ in range(n): #fast is n steps ahead
            fast = fast.next
        while fast.next:
            slow = slow.next  #stops right before nth element
            fast = fast.next   #stops right after nth element
        slow.next = slow.next.next 
        return dummy.next


s = Solution()
l = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
node(s.removeNthFromEnd(l, 2))