# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 and not l2:
            return None

        current = head = ListNode(0)
        while l1 and l2:
            a, b = l1.val, l2.val
            if a < b:
                current.next = ListNode(a)
                l1 = l1.next
            else:
                current.next = ListNode(b)
                l2 = l2.next

            current = current.next

        if l2 and not l1:
            l1 = l2

        while l1:
            current.next = ListNode(l1.val)
            current = current.next
            l1 = l1.next

        return head.next
