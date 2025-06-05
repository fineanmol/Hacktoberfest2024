# Python code to delete a node in AVL tree
# Generic tree node class


class TreeNode():
	def __init__(self, val):
		self.count = 1 # assigning count variable so that during insertion in will be incremented for duplicate values
		# and during deletion, it will be decremented if has multiple copies.
		self.height = 1
		self.val = val
		self.left = None
		self.right = None
# only insertion and deletion will be affected. if multiple copies are there, entry(count) will be printed during traversal.

# AVL tree class which supports insertion,
# deletion operations


class AVL_Tree(object):

	def insert(self, root, key):

		# Step 1 - Perform normal BST
		if not root:
			return TreeNode(key)
		else if key < root.val:
			root.left = self.insert(root.left, key)
		else if key > root.val:
			root.right = self.insert(root.right, key)
		else:
			root.count += 1 # incrementing count if same entry is inserted.

		# Step 2 - Update the height of the
		# ancestor node
		root.height = 1 + max(self.getHeight(root.left),
							self.getHeight(root.right))

		# Step 3 - Get the balance factor
		balance = self.getBalance(root)

		# Step 4 - If the node is unbalanced,
		# then try out the 4 cases
		# Case 1 - Left Left
		if balance > 1 and key < root.left.val:
			return self.rightRotate(root)

		# Case 2 - Right Right
		if balance < -1 and key > root.right.val:
			return self.leftRotate(root)

		# Case 3 - Left Right
		if balance > 1 and key > root.left.val:
			root.left = self.leftRotate(root.left)
			return self.rightRotate(root)

		# Case 4 - Right Left
		if balance < -1 and key < root.right.val:
			root.right = self.rightRotate(root.right)
			return self.leftRotate(root)

		return root

	# Recursive function to delete a node with
	# given key from subtree with given root.
	# It returns root of the modified subtree.
	def delete(self, root, key):

		# Step 1 - Perform standard BST delete
		if not root:
			return root

		else if key < root.val:
			root.left = self.delete(root.left, key)

		else if key > root.val:
			root.right = self.delete(root.right, key)

		else:
			if root.count > 1: # if count is more than one i.e multiple copies are there
				root.count -= 1 # just decrement count
				return root # so that one copy will be deleted and return

			if root.left is None:
				temp = root.right
				root = None
				return temp

			else if root.right is None:
				temp = root.left
				root = None
				return temp

			temp = self.getMinValueNode(root.right)
			root.val = temp.val
			root.right = self.delete(root.right,
									temp.val)

		# If the tree has only one node,
		# simply return it
		if root is None:
			return root

		# Step 2 - Update the height of the
		# ancestor node
		root.height = 1 + max(self.getHeight(root.left),
							self.getHeight(root.right))

		# Step 3 - Get the balance factor
		balance = self.getBalance(root)

		# Step 4 - If the node is unbalanced,
		# then try out the 4 cases
		# Case 1 - Left Left
		if balance > 1 and self.getBalance(root.left) >= 0:
			return self.rightRotate(root)

		# Case 2 - Right Right
		if balance < -1 and self.getBalance(root.right) <= 0:
			return self.leftRotate(root)

		# Case 3 - Left Right
		if balance > 1 and self.getBalance(root.left) < 0:
			root.left = self.leftRotate(root.left)
			return self.rightRotate(root)

		# Case 4 - Right Left
		if balance < -1 and self.getBalance(root.right) > 0:
			root.right = self.rightRotate(root.right)
			return self.leftRotate(root)

		return root

	def leftRotate(self, z):

		y = z.right
		T2 = y.left

		# Perform rotation
		y.left = z
		z.right = T2

		# Update heights
		z.height = 1 + max(self.getHeight(z.left),
						self.getHeight(z.right))
		y.height = 1 + max(self.getHeight(y.left),
						self.getHeight(y.right))

		# Return the new root
		return y

	def rightRotate(self, z):

		y = z.left
		T3 = y.right

		# Perform rotation
		y.right = z
		z.left = T3

		# Update heights
		z.height = 1 + max(self.getHeight(z.left),
						self.getHeight(z.right))
		y.height = 1 + max(self.getHeight(y.left),
						self.getHeight(y.right))

		# Return the new root
		return y

	def getHeight(self, root):
		if not root:
			return 0

		return root.height

	def getBalance(self, root):
		if not root:
			return 0

		return self.getHeight(root.left) - self.getHeight(root.right)

	def getMinValueNode(self, root):
		if root is None or root.left is None:
			return root

		return self.getMinValueNode(root.left)

	def preOrder(self, root):

		if not root:
			return

		print("{}({}) ".format(root.val, root.count), end="")
		self.preOrder(root.left)
		self.preOrder(root.right)


myTree = AVL_Tree()
root = None
nums = [9, 5, 10, 5, 9, 7, 17]

for num in nums:
	root = myTree.insert(root, num)

# Preorder Traversal
print("Preorder Traversal after insertion -")
myTree.preOrder(root)
print()

# Delete
key = 10
root = myTree.delete(root, key)
key = 10
root = myTree.delete(root, key)
key = -1
root = myTree.delete(root, key)
key = 0
root = myTree.delete(root, key)

# Preorder Traversal
print("Preorder Traversal after deletion -")
myTree.preOrder(root)
print()

# This code is contributed by Ajitesh Pathak
