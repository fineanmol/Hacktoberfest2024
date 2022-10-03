# Python program for inorder,preorder and postorder tree traversals

# Making Node
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


# A function for inorder tree traversal
def printInorder(root):

    if root:

        # First recur on left child
        printInorder(root.left)

        # then print the data of node
        print(root.val, end=" "),

        # now recur on right child
        printInorder(root.right)

# A function for preorder tree traversal


def printPreorder(root):

    if root:

        # First print the data of node
        print(root.val, end=" "),

        # Then recur on left child
        printPreorder(root.left)

        # Finally recur on right child
        printPreorder(root.right)

# A function for postorder tree traversal


def printPostorder(root):

    if root:

        # First recur on left child
        printPostorder(root.left)

        # the recur on right child
        printPostorder(root.right)

        # now print the data of node
        print(root.val, end=" "),


# Driver code
if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(7)
    root.left.left = Node(6)
    root.left.right = Node(5)

    #     1
    #    / \
    #   2   7
    #  / \
    # 6   5


print("\nInorder traversal of binary tree: ")
printInorder(root)
print("\nPreorder traversal of binary tree: ")
printPreorder(root)
print("\nPostorder traversal of binary tree: ")
printPostorder(root)
print("\n")
