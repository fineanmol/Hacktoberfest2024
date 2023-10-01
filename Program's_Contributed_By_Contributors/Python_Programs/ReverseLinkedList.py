# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        ans = []
        while head:
            ans.append(head.val)
            head = head.next
        print(ans)
        li1 = ans[:left-1]
        li2 = ans[left-1:right]
        li3 = ans[right:]
        print(li1)
        print(li2)
        print(li3)
        nums = li1 + li2[::-1] + li3
        dummy = ListNode()
        current = dummy
        for i in nums:
            current.next = ListNode(i)
            current = current.next
        return dummy.next
#I displahyed an easy way to reverse a linekd list rather than showing how to use nodes and pointers
