class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
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
