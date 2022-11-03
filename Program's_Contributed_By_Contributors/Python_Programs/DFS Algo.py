class Node:
    def __init__(self, state, parent, actions, totalCost):
        self.state = state
        self.parent = parent
        self.actions = actions
        self.totalCost = totalCost


def actionSequence(graph, goalState):
    global solution
    solution = [goalState]
    currentParent = graph[goalState].parent
    while currentParent is not None:
        solution.append(currentParent)
        currentParent = graph[currentParent].parent
    solution.reverse()
    return solution


def DFS():
    initialState = 'D'
    goalState = 'C'
    graph = {'A': Node('A', None, ['B', 'C', 'E'], None),
             'B': Node('B', None, ['A', 'D', 'E'], None),
             'C': Node('C', None, ['A', 'F', 'G'], None),
             'D': Node('D', None, ['B', 'E'], None),
             'E': Node('E', None, ['A', 'B', 'D'], None),
             'F': Node('F', None, ['C'], None),
             'G': Node('G', None, ['C'], None)}
    frontier = [initialState]
    explored = []
    while len(frontier) != 0:
        currentNode = frontier.pop(len(frontier) - 1)
        explored.append(currentNode)
        currentChildren = 0
        for child in graph[currentNode].actions:
            if child not in frontier and child not in explored:
                graph[child].parent = currentNode
                if graph[child].state == goalState:
                    print('Explored:', explored)
                    return actionSequence(graph, goalState)
                currentChildren = currentChildren + 1
                frontier.append(child)
        if currentChildren == 0:
            del explored[len(explored) - 1]


solution = DFS()
print('Path:', solution)
