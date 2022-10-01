class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next =next

class LinkedList:
    def __init__(self):
        self.head = None

    def print(self):
        if self.head == None:
            print("Linked list is empty!")
            return
        itr = self.head
        llstr = ""
        while itr:
            llstr += str(itr.data)+" --> " if itr.next else str(itr.data)
            itr = itr.next
        print(llstr)

    def get_length(self):
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next
        print(count)
        return count

    def insert_at_beginning(self, data):
        node = Node(data, self.head)
        self.head = node

    def insert_at_end(self, data):
        if self.head == None:
            self.head = Node(data, None)
            return
        itr = self.head
        while itr.next:
            itr = itr.next

        itr.next = Node(data, None)

    def insert_at(self, index, data):
        if index<0 or index>self.get_length():
            raise Exception("Invalid index out of bound!")

        if index == 0:
            self.insert_at_beginning(data)
            return

        itr = self.head
        count = 0
        while itr:
            if count == index-1:
                node = Node(data, itr.next)
                itr.next = node
                break

            itr = itr.next
            count +=1
    def remove_at(self, index):
        if index<0 or index>= self.get_length():
            raise Exception("Invalid index out of bound!")

        if index==0:
            self.head = self.head.next
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                itr.next = itr.next.next
                break

            itr = itr.next
            count += 1

    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data)

    def insert_after_value(self, data_after, data_to_insert):
        # Search for first occurance of data_after value in linked list
        # Now insert data_to_insert after data_after node
        if self.head == None:
            return
        if self.head.data == data_after:
            self.head.next = Node(data_to_insert, self.head.next)
            return

        itr = self.head
        while itr:
            if itr.data == data_after:
                itr.next = Node(data_to_insert, itr.next)
                break
            itr = itr.next


    def remove_by_value(self, data):
        # Remove first node that contains data
        if self.head == None:
            return

        if self.head == data:
            self.head = self.head.next
            return

        itr = self.head
        while itr.next:
            if itr.next.data == data:
                itr.next = itr.next.next
                break
            itr = itr.next


if __name__=="__main__":
    ll = LinkedList()
    ll.insert_values(["banana","mango","grapes","orange"])
    ll.print()
    ll.insert_after_value("mango","apple")
    ll.print()
    ll.remove_by_value("orange")
    ll.print()
    ll.remove_by_value("figs")
    ll.print()
    ll.remove_by_value("banana")
    ll.remove_by_value("mango")
    ll.remove_by_value("apple")
    ll.remove_by_value("grapes")
    ll.print()



""""https://leetcode.com/problems/remove-nth-node-from-end-of-list/"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
#class Solution:
#    def removeNthElement(head, n):
#        if n == 1:
#            return head.next
#        if not head:
#            return head
#        head.next = Solution.removeNthElement(head.next, n - 1)
#        return head

#    def reverse(head):
#        last = None
#        while head:
#            head.next, last, head = last, head, head.next

#        return last

#    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
#        return Solution.reverse(Solution.removeNthElement(Solution.reverse(head), n))


