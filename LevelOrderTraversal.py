class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

def levelOrder(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        level = []
        next_queue = []

        for node in queue:
            level.append(node.val)

            if node.left:
                next_queue.append(node.left)
            if node.right:
                next_queue.append(node.right)

        result.append(level)
        queue = next_queue

    return result

 
def printLevelOrder(result):
    for level in result:
        print(level)

 
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

 
result = levelOrder(root)

 
print("Level Order Traversal:")
printLevelOrder(result)
