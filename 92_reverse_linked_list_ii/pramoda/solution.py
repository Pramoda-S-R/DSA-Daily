from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next: Optional[ListNode] = None):
        self.val = val
        self.next = next


def node(head: ListNode):
    while head:
        print(head.val, "->", end=" ")
        head = head.next


class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        prevLeft = dummy

        for _ in range(left - 1):
            prevLeft = prevLeft.next

        curr = prevLeft.next
        prev = None

        for _ in range(right - left + 1):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        prevLeft.next.next = curr
        prevLeft.next = prev

        return dummy.next

s = Solution()
l1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
node(s.reverseBetween(head=l1, left=2, right=4))