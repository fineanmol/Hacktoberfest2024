# 2. Add Two Numbers
# https://leetcode.com/problems/add-two-numbers/
#  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode(0)  # Create a dummy node to simplify code
        current = dummy_head
        carry = 0

        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0

            total = x + y + carry
            carry = total // 10  # Calculate the carry for the next step
            current.next = ListNode(total % 10)  # Create a new node for the sum
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        if carry > 0:
            current.next = ListNode(carry)  # If there's a carry left, create a new node

        return dummy_head.next  # Return the result linked list (skip the dummy node)
