# A class to store a binary tree node
class Node:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right
 
 
# Function to print all nodes of a given level from left to right
def printLevel(root, level):
 
    # base case
    if root is None:
        return False
 
    if level == 1:
        print(root.key, end=' ')
 
        # return true if at least one node is present at a given level
        return True
 
    left = printLevel(root.left, level - 1)
    right = printLevel(root.right, level - 1)
 
    return left or right
 
 
# Function to print level order traversal of a given binary tree
def levelOrderTraversal(root):
 
    # start from level 1 — till the height of the tree
    level = 1
 
    # run till printLevel() returns false
    while printLevel(root, level):
        level = level + 1
 
 
if __name__ == '__main__':
 
    root = Node(15)
    root.left = Node(10)
    root.right = Node(20)
    root.left.left = Node(8)
    root.left.right = Node(12)
    root.right.left = Node(16)
    root.right.right = Node(25)
 
    levelOrderTraversal(root)