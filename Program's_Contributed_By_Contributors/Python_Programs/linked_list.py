class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        current = self.head
        if current == None:
            self.head = new_node
            return
        while(current.next):
            current = current.next
        current.next = new_node

    def insert(self, data, position):
        """
        This takes data which to be inserted 
        and position at which data should be inserted
        """
        new_node = Node(data)
        current = self.head
        count = 0
        while current is not None:
            if position == 0:
                self.head = new_node
                temp = self.head
                temp.next = current
                return
            if count == position-1:
                temp = current.next
                current.next = new_node
                x = new_node
                x.next = temp
                return
            count += 1
            current = current.next
        if position > count:
            print('index out of range')

    def print_list(self):
        current = self.head
        while(current != None):
            print(current.data)
            current = current.next
