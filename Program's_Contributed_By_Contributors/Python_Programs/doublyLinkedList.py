class Node:
    def __init__(self, value) -> None:
        self.value = value
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self, value) -> None:
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    def pop_first(self):
        if self.length == 0:
            return None
        temp = self.head
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
            temp.next = None
        self.length -= 1
        return temp

    def pop(self):
        if self.length == 0:
            return None
        temp = self.tail
        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
            temp.prev = None
        self.length -= 1
        return temp

    def append(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        self.length += 1
        return True

    def print_list(self):
        temp = self.head
        print("[", end="")
        while temp:
            if temp.next != None:
                print(temp.value, end=", ")
            else:
                print(f"{temp.value}]")
            temp = temp.next

    def append(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        self.length += 1
        return True

    def prepend(self, value):
        new_node = Node(value)
        if self.length == 0:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.length += 1
        return True

    def get(self, index):
        if index < 0 or index >= self.length:
            return None
        temp = self.head
        if index < self.length/2:
            for _ in range(index):
                temp = temp.next
        else:
            temp = self.tail
            for _ in range(self.length - 1, index, -1):
                temp = temp.prev
        return temp

    def set_value(self, index, value):
        temp = self.get(index)
        if temp:
            temp.value = value
            return True
        return False


my_doubly_linked_list = DoublyLinkedList(11)

print("")

print('before append:')
my_doubly_linked_list.print_list()
print('after append:')
my_doubly_linked_list.append(3)
my_doubly_linked_list.append(23)
my_doubly_linked_list.append(7)
my_doubly_linked_list.append(90)
my_doubly_linked_list.append(8)
my_doubly_linked_list.append(31)
my_doubly_linked_list.print_list()

print("")
print("")

print('before pop:')
my_doubly_linked_list.print_list()
print('after pop:')
my_doubly_linked_list.pop()
my_doubly_linked_list.print_list()

print("")
print("")

print('before prepend:')
my_doubly_linked_list.print_list()
my_doubly_linked_list.prepend(1)
print('after prepend:')
my_doubly_linked_list.print_list()

print("")
print("")

print('before pop_first:')
my_doubly_linked_list.print_list()
print('after pop_first:')
my_doubly_linked_list.pop_first()
my_doubly_linked_list.print_list()

print("")
print("")

print('get(2) -> should return 23:')
print(my_doubly_linked_list.get(2).value)

print("")
print("")

print('before set_value(2, 9):')
my_doubly_linked_list.print_list()
my_doubly_linked_list.set_value(2, 9)
print('after set_value(2, 9):')
my_doubly_linked_list.print_list()

print("")
print("")

try:
    print(f'Head: {my_doubly_linked_list.head.value}')
    print(f'Tail: {my_doubly_linked_list.tail.value}')
except:
    print(f'Head: {my_doubly_linked_list.head}')
    print(f'Tail: {my_doubly_linked_list.tail}')

print(f'Length: {my_doubly_linked_list.length}')
