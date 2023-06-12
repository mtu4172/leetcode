# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        head = None
        temp = None
        while l1 and l2:
            val = l1.val + l2.val + carry
            carry = val // 10
            val = val % 10
            if head is None:
                head = ListNode(val)
                temp = head
            else:
                temp.next = ListNode(val)
                temp = temp.next
            l1 = l1.next
            l2 = l2.next
        while l1:
            val = l1.val + carry
            carry = val // 10
            val = val % 10
            if head is None:
                head = ListNode(val)
                temp = head
            else:
                temp.next = ListNode(val)
                temp = temp.next
            l1 = l1.next
        while l2:
            val = l2.val + carry
            carry = val // 10
            val = val % 10
            if head is None:
                head = ListNode(val)
                temp = head
            else:
                temp.next = ListNode(val)
                temp = temp.next
            l2 = l2.next
        if carry is 1:
            temp.next = ListNode(1)
        return head
        