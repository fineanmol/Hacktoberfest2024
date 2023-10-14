# Singly Linked List without any size limit
class Node:
    def __init__(self, dataval = None, nextval = None):
        self.dataval = dataval
        self.nextval = nextval

    def __repr__(self):
        return repr(self.dataval)
    

class LinkedList:
    def __init__(self, size):
        self.head = None


#Appending into a linkedlist

    def add_begin(self, value):
        if not self.head:
            new_node = Node(value)
            self.head = new_node
            return
        curr = self.head
        new_node = Node(value)
        new_node.nextval = curr
        self.head = new_node
    
    def add_end(self, value):
        curr = self.head
        while curr.nextval != None:
            curr = curr.nextval
        new_node = Node(value)
        curr.nextval = new_node

    def add_index(self, value , index):
        pos =0
        curr = self.head
        while curr and pos != index-1:
            curr = curr.nextval
            pos += 1
        next = curr.nextval
        new_node = Node(value)
        curr.nextval = new_node
        new_node.nextval = next
        return
    

#Deleting from a Linkedlist

    def delete_begin(self):
        if self.head == None:
            print("Linkedlist is empty")
            return
        curr = self.head
        self.head = curr.nextval
        curr.nextval = None

    def delete_end(self):
        if self.head == None:
            print("Linkedlist is empty")
            return
        curr = self.head
        while curr.nextval != None:
            prev = curr
            curr = curr.nextval
        prev.nextval = None

    def delete_index(self, index):
        if self.head == None:
            print("Linkedlist is empty")
            return
        pos = 0
        curr = self.head
        while curr and pos != index-1:
            prev = curr
            curr = curr.nextval
            pos += 1
        prev.nextval = curr.nextval
        curr.nextval = None
        return
    
# Altering a value from a specific location

    def alter_index(self, value, index):
        if self.head == None:
            print("Linkedlist is empty")
            return
        pos = 0
        curr = self.head
        while curr and pos != index-1:
            curr = curr.nextval
            pos += 1
        alter = curr.nextval
        alter.dataval = value
        
#display functions

    def display_linkedlist(self):
        if self.head == None:
            print("Linkedlist is empty")
            return
        curr = self.head
        while curr:
            print(curr.dataval)
            curr = curr.nextval

    def size(self):
        if self.head == None:
            print("Linkedlist is empty")
            return
        curr = self.head
        size = 0
        while curr:
            size += 1
            curr = curr.nextval
        return size
        


