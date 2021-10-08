# import required module
import ctypes



# create node class
class Node:
	def __init__(self, value):
		self.value = value
		self.npx = 0


		
# create linked list class
class XorLinkedList:

	# constructor
	def __init__(self):
		self.head = None
		self.tail = None
		self.__nodes = []

	# method to insert node at beginning
	def InsertAtStart(self, value):
		node = Node(value)
		if self.head is None: # If list is empty
			self.head = node
			self.tail = node
		else:
			self.head.npx = id(node) ^ self.head.npx
			node.npx = id(self.head)
			self.head = node
		self.__nodes.append(node)

	# method to insert node at end
	def InsertAtEnd(self, value):
		node = Node(value)
		if self.head is None: # If list is empty
			self.head = node
			self.tail = node
		else:
			self.tail.npx = id(node) ^ self.tail.npx
			node.npx = id(self.tail)
			self.tail = node
		self.__nodes.append(node)

	# method to remove node at beginning
	def DeleteAtStart(self):
		if self.isEmpty(): # If list is empty
			return "List is empty !"
		elif self.head == self.tail: # If list has 1 node
			self.head = self.tail = None
		elif (0 ^ self.head.npx) == id(self.tail): # If list has 2 nodes
			self.head = self.tail
			self.head.npx = self.tail.npx = 0
		else: # If list has more than 2 nodes
			res = self.head.value
			x = self.__type_cast(0 ^ self.head.npx) # Address of next node
			y = (id(self.head) ^ x.npx) # Address of next of next node
			self.head = x
			self.head.npx = 0 ^ y
			return res

	# method to remove node at end
	def DeleteAtEnd(self):
		if self.isEmpty(): # If list is empty
			return "List is empty !"
		elif self.head == self.tail: # If list has 1 node
			self.head = self.tail = None
		elif self.__type_cast(0 ^ self.head.npx) == (self.tail): # If list has 2 nodes
			self.tail = self.head
			self.head.npx = self.tail.npx = 0
		else: # If list has more than 2 nodes
			prev_id = 0
			node = self.head
			next_id = 1
			while next_id:
				next_id = prev_id ^ node.npx
				if next_id:
					prev_id = id(node)
					node = self.__type_cast(next_id)
			res = node.value
			x = self.__type_cast(prev_id).npx ^ id(node)
			y = self.__type_cast(prev_id)
			y.npx = x ^ 0
			self.tail = y
			return res

	# method to traverse linked list
	def Print(self):
		"""We are printing values rather than returning it bacause
		for returning we have to append all values in a list
		and it takes extra memory to save all values in a list."""

		if self.head != None:
			prev_id = 0
			node = self.head
			next_id = 1
			print(node.value, end=' ')
			while next_id:
				next_id = prev_id ^ node.npx
				if next_id:
					prev_id = id(node)
					node = self.__type_cast(next_id)
					print(node.value, end=' ')
				else:
					return
		else:
			print("List is empty !")

	# method to traverse linked list in reverse order
	def ReversePrint(self):

		# Print Values is reverse order.
		"""We are printing values rather than returning it bacause
		for returning we have to append all values in a list
		and it takes extra memory to save all values in a list."""

		if self.head != None:
			prev_id = 0
			node = self.tail
			next_id = 1
			print(node.value, end=' ')
			while next_id:
				next_id = prev_id ^ node.npx
				if next_id:
					prev_id = id(node)
					node = self.__type_cast(next_id)
					print(node.value, end=' ')
				else:
					return
		else:
			print("List is empty !")

	# method to get length of linked list
	def Length(self):
		if not self.isEmpty():
			prev_id = 0
			node = self.head
			next_id = 1
			count = 1
			while next_id:
				next_id = prev_id ^ node.npx
				if next_id:
					prev_id = id(node)
					node = self.__type_cast(next_id)
					count += 1
				else:
					return count
		else:
			return 0

	# method to get node data value by index
	def PrintByIndex(self, index):
		prev_id = 0
		node = self.head
		for i in range(index):
			next_id = prev_id ^ node.npx

			if next_id:
				prev_id = id(node)
				node = self.__type_cast(next_id)
			else:
				return "Value dosn't found index out of range."
		return node.value

	# method to check if the liked list is empty or not
	def isEmpty(self):
		if self.head is None:
			return True
		return False

	# method to return a new instance of type
	def __type_cast(self, id):
		return ctypes.cast(id, ctypes.py_object).value


		
# Driver Code

# create object
obj = XorLinkedList()

# insert nodes
obj.InsertAtEnd(2)
obj.InsertAtEnd(3)
obj.InsertAtEnd(4)
obj.InsertAtStart(0)
obj.InsertAtStart(6)
obj.InsertAtEnd(55)

# display length
print("\nLength:", obj.Length())

# traverse
print("\nTraverse linked list:")
obj.Print()

print("\nTraverse in reverse order:")
obj.ReversePrint()

# display data values by index
print('\nNodes:')
for i in range(obj.Length()):
	print("Data value at index", i, 'is', obj.PrintByIndex(i))

# removing nodes
print("\nDelete Last Node: ", obj.DeleteAtEnd())
print("\nDelete First Node: ", obj.DeleteAtStart())

# new length
print("\nUpdated length:", obj.Length())

# display data values by index
print('\nNodes:')
for i in range(obj.Length()):
	print("Data value at index", i, 'is', obj.PrintByIndex(i))

# traverse
print("\nTraverse linked list:")
obj.Print()

print("\nTraverse in reverse order:")
obj.ReversePrint()
