class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        temp = current = ListNode()
        while list1 and list2:
            if list1.val < list2.val:
                current.next, list1 = list1, list1.next
            else:
                current.next, list2 = list2, list2.next
            current = current.next
        current.next = list1 or list2
        return temp.next
