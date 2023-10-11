import random, math


class Node:
    def __init__(self, y, x) -> None:
        self.state = random.randint(0, 1)
        self.x = x
        self.y = y

        self.parentX = 0
        self.parentY = 0
        self.neighboursCord = []

        self.g = float('inf')
        self.h = 0
        self.f = 0


def find_neighbours(node: Node):
    # Remove all the walls and the outside-of-map nodes
    for dir in dirs:
        neighbour = (node.y + dir[0], node.x + dir[1])
        if neighbour in walkable:
            node.neighboursCord.append(neighbour)


def calc_H(y, x, goal):
    # Euclidean heuristic
    dx = abs(x - goal[1])
    dy = abs(y - goal[0])
    return math.sqrt(dx*dx + dy*dy)


def cal_G(current, neighbour):
    new_g = Map[current[0]][current[1]].g + math.sqrt(2)
    if neighbour[0] == current[0] or neighbour[1] == current[1]:
        new_g = Map[current[0]][current[1]].g + 1
    return new_g


def cal_F(y, x):
    Map[y][x].f = Map[y][x].g + Map[y][x].h


def tracePath(goal, start):
    y = goal[0]
    x = goal[1]

    # Trace backwards from the goal to the start using the parent pointer
    while not (Map[y][x].parentY == start[0] and Map[y][x].parentX == start[1]):
        path.append((y, x))
        temp_y = Map[y][x].parentY
        temp_x = Map[y][x].parentX
        y = temp_y
        x = temp_x
    path.append((y, x))
    path.append((start[0], start[1]))


def mapGen(row, column, start, goal):
    for y in range(row):
        line = []
        for x in range(column):
            node = Node(y, x)
            line.append(node)
            if node.state == 1:
                walkable.add((y, x))
        Map.append(line)
    
    # Make sure that start and goal are not walls
    Map[start[0]][start[1]].state = 1
    Map[goal[0]][goal[1]].state = 1
    walkable.add(start)
    walkable.add(goal)

    # Precomputed h() cost for all nodes
    for y in range(row):
        for x in range(column):
            find_neighbours(Map[y][x])
            Map[y][x].h = calc_H(y, x, goal)


def render():
    for row in Map:
        for node in row:
            if (node.y, node.x) == goal:
                print('🟪', end='')
            elif (node.y, node.x) == start:
                print('🟦', end='')
            elif (node.y, node.x) in path:
                print('🟩', end='')
            elif (node.y, node.x) in explored:
                print('🟨', end='')
            elif node.state == 1:
                print('⬜', end='')
            else:
                print('⬛', end='')
        print('')


# Setting up the graph
width, height = 15, 15
dirs = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, -1), (-1, 1)]  # defining edges of the graph
start = (random.randint(0, height - 1), random.randint(0, width - 1))
goal = (random.randint(0, height - 1), random.randint(0, width - 1))
Map = []  # contains all the nodes to render
walkable = set()  # contains coordinates that can be visited

# Setting up A*
path = []
explored = []
frontier = []

mapGen(width, height, start, goal)

# Showcasing the map
print("The Map:")
render()
print("Keys:"
      "\n⬜ road"
      "\n⬛ wall"
      "\n🟪 goal"
      "\n🟦 start")


# The A* function that caused me internal brain bleeding for 2 months
def A_star_algorithm(start, goal):
    frontier.append(start)

    while len(frontier) != 0:
        if start == goal:
            print("Starting position coincides with the goal")
            return
        Map[start[0]][start[1]].g = 0
        
        currentNode = min(frontier, key=lambda x: Map[x[0]][x[1]].f)
        frontier.remove(currentNode)
        explored.append(currentNode)

        if currentNode == goal:
            tracePath(goal, start)
            render()
            print("Keys:"
                "\n⬜ road"
                "\n⬛ wall"
                "\n🟩 path generated"
                "\n🟨 explored nodes"
                "\n🟪 goal"
                "\n🟦 start")
            return

        for neighbourNode in Map[currentNode[0]][currentNode[1]].neighboursCord:
            if neighbourNode in explored:
                continue

            cost = cal_G(currentNode, neighbourNode)

            if (neighbourNode not in frontier) or (cost < Map[neighbourNode[0]][neighbourNode[1]].g):
                Map[neighbourNode[0]][neighbourNode[1]].g = cost
                cal_F(neighbourNode[0], neighbourNode[1])
                Map[neighbourNode[0]][neighbourNode[1]].parentY = currentNode[0]
                Map[neighbourNode[0]][neighbourNode[1]].parentX = currentNode[1]
                if neighbourNode not in frontier:
                    frontier.append(neighbourNode)
    
    print("No solution :(")


print("\nThe Solution:")
A_star_algorithm(start, goal)