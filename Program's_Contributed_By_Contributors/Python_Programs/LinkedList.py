class Node: 
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:
	def __init__(self):
		self.head = None

	def traverse(self):
		temp = self.head
		data = []
		while (temp):
			data.append(temp.data)
			temp = temp.next
		return data

	def search(self,item): 
		temp = self.head
		i = 0
		while (temp):
			if(temp.data == item):
				return {"data": temp.data, "position": i}
			i += 1
			temp = temp.next
		return None

	def length(self):
		count = 0
		temp = self.head
		while (temp):
			count += 1
			temp = temp.next
		return count

	def insert_last(self,val):
		newNode = Node(val)
		if self.head == None:
			self.head = newNode
		else:
			curr = self.head
			while curr.next != None:
				curr = curr.next
			curr.next = newNode

	def insert_first(self, val):
		newNode = Node(val)
		if self.head == None:
			self.head = newNode
		else:
			newNode.next = self.head
			self.head = newNode

	def delete(self, val):
		if self.head == None: 
			return None
		else:
			curr = self.head
			prev = self.head
			if self.head.data == val:
				self.head = self.head.next
				curr.next = None
			else:
				while curr != None and curr.data != val:
					prev = curr
					curr = curr.next
				if curr != None:
				   prev.next = curr.next
				   curr.next = None 

def main():
	List = LinkedList()

	List.insert_last(1)
	List.insert_last(2)
	List.insert_last(3)
	List.insert_last(4)
	List.insert_last(5)
	List.insert_last(6)
	List.insert_first(0)

	print(List.search(2))

	print(List.traverse())

	List.delete(0)

	print(List.traverse())


if __name__ == '__main__':
	main()
