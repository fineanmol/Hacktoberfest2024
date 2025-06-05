class newNode:
    def __init__(self,data) -> None:
        self.left = None
        self.right = None
        self.data = data

def level_order(root):
    queue = [root,None]
    traversal = []
    level = []
    while(True):
        temp = queue.pop(0)
        if temp==None:
            if len(queue)==0:
                traversal.append(level)
                return traversal
            queue.append(None)
            traversal.append(level)
            level = []
            continue
        if temp.left!=None: 
            queue.append(temp.left)
        if temp.right!=None:
            queue.append(temp.right)
        level.append(temp.data)

def levelorder(root):
    queue = [root]
    traversal = []
    while(len(queue)!=0):
        temp = queue.pop(0)
        traversal.append(temp.data)
        if temp.left:
            queue.append(temp.left)
        if temp.right:
            queue.append(temp.right)
    return traversal

def left_view(root):
    left_view = []
    traversal = level_order(root)
    for i in traversal:
        left_view.append(i[0])
    return left_view

def right_view(root):
    right_view = []
    traversal = level_order(root)
    for i in traversal:
        right_view.append(i[-1])
    return right_view

root = newNode(10)
root.left = newNode(11)
root.left.left = newNode(7)
root.right = newNode(9)
root.right.left = newNode(15)
root.right.right = newNode(8)
print("Level order traversal of binary tree is ",level_order(root))
print("Level order traversal of binary tree is ",levelorder(root))
print("Left view of binary tree is ",left_view(root))
print("Rigth view of binary tree is ",right_view(root))