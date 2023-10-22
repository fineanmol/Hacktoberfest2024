class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

    def is_terminal_node(self):
        return len(self.children) == 0

    def evaluate(self):
        return self.value

    def add_child(self, child):
        self.children.append(child)

    def get_children(self):
        return self.children


def alpha_beta(node, depth, alpha, beta, maximizing_player):
    if depth == 0 or node.is_terminal_node():
        return node.evaluate()

    if maximizing_player:
        value = float('-inf')
        for child in node.children:
            value = max(value, alpha_beta(child, depth - 1, alpha, beta, False))
            alpha = max(alpha, value)
            if alpha >= beta:
                break
        return value
    else:
        value = float('inf')
        for child in node.children:
            value = min(value, alpha_beta(child, depth - 1, alpha, beta, True))
            beta = min(beta, value)
            if alpha >= beta:
                break
        return value
    
root = Node(5)
child1 = Node(15)
child2 = Node(2)
child3 = Node(9)
child3.add_child(Node(5))  # Add a child to node with value 9
child3.add_child(Node(28))  # Add another child to node with value 9

root.add_child(child1)
root.add_child(child2)
root.add_child(child3)
result = alpha_beta(root, 3, float('-inf'), float('inf'),True)
print(result)
