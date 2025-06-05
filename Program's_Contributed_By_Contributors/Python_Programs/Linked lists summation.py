class Node:
    def __init__(self,data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node


    def addTwoLists(self, first, second):
        prev = None
        temp = None
        carry = 0

        while(first is not None or second is not None):
            fdata = 0 if first is None else first.data
            sdata = 0 if second is None else second.data
            sum = carry + fdata + sdata

            carry = 1 if sum>=10 else 0
            sum = sum if sum<10 else sum%10

            temp = Node(sum)

            if self.head is None:
                self.head = temp
            else:
                prev.next = temp

            prev = temp

            if first is not None:
                first = first.next
            if second is not None:
                second = second.next    

        if carry>0:
            temp.next = Node(carry)
        

    def printList(self):
        temp = self.head
        ans = ""
        while(temp):
            ans+= str(temp.data)
            # print(temp.data,end=' ')
            temp = temp.next
        
        print(ans[::-1])


# Initialising Linked Lists
first = LinkedList()
second = LinkedList()


first.push(3)
first.push(4)
first.push(2)
print("First List is")
first.printList()

second.push(4)
second.push(6)
second.push(5)
print(" ")
print("Second List is ")
second.printList()

res = LinkedList()
res.addTwoLists(first.head, second.head)
print(" ")
print("resultant list is")
res.printList()


                    

