# A single node of a singly linked list
class Node:
  # constructor
  def __init__(self, data, next=None): 
    self.data = data
    self.next = next

# Creating a single node
first = Node(3)
print(first.data)
