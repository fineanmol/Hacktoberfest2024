class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

        
        
#Deletion from the beginning of the list 
    def delete_first(self):
        if self.head is None:
            print("Underflow: Linked list is empty")
        else:
            del self.head
            self.head = self.head.next

            
            
#Deletion from the end of the list 
    def delete_last(self):
        if self.head is None:
            print("Underflow: Linked list is empty")
        else:
            temp = self.head
            while temp.next is not None:
                prev = temp
                temp = temp.next
            prev.next = None
            
            
            
#Deletion from a specific position in the list 
    def delete_at_position(self, pos):
        if pos < 1:
            print("Invalid position: First position should be >= 1")
        elif pos == 1:
            del self.head
            self.head = self.head.next
        else:
            temp = self.head
            for i in range(1, pos):
                if temp is not None:
                    prev = temp
                    temp = temp.next
            if temp is not None:
                prev.next = temp.next

    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data)
            current = current.next

if __name__ == '__main__':
    llist = LinkedList()

    llist.head = Node(1)
    second = Node(2)
    third = Node(3)

    llist.head.next = second
    second.next = third

    print('Linked list before deletion:')
    llist.print_list()

    llist.delete_at_position(2)

    print('\nLinked list after deletion:')
    llist.print_list()