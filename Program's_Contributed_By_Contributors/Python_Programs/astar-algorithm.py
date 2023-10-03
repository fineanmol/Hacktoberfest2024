class Node:
    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position

        self.g = 0  # Cost from start node to current node
        self.h = 0  # Cost from current node to the goal node
        self.f = 0  # Total cost (g + h)


def astar(maze, start, end):
    # Create start and end nodes
    start_node = Node(None, start)
    end_node = Node(None, end)

    # Initialize open and closed lists
    open_list = []
    closed_list = []

    # Add the start node
    open_list.append(start_node)

    # Define movement directions (4 directions: up, down, left, right)
    directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

    # Loop until the open list is empty
    while open_list:
        # Get the current node
        current_node = open_list[0]
        current_index = 0
        for index, item in enumerate(open_list):
            if item.f < current_node.f:
                current_node = item
                current_index = index

        # Pop current node from open list and add it to the closed list
        open_list.pop(current_index)
        closed_list.append(current_node)

        # If the current node is the end node, reconstruct the path and return it
        if current_node.position == end_node.position:
            path = []
            while current_node is not None:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]  # Return reversed path

        # Generate children nodes
        children = []
        for new_direction in directions:
            node_position = (
                current_node.position[0] + new_direction[0],
                current_node.position[1] + new_direction[1],
            )

            # Check if the node is within the maze boundaries
            if (
                node_position[0] > (len(maze) - 1)
                or node_position[0] < 0
                or node_position[1] > (len(maze[len(maze) - 1]) - 1)
                or node_position[1] < 0
            ):
                continue

            # Check if the node is not a wall
            if maze[node_position[0]][node_position[1]] != 0:
                continue

            # Create a new node
            new_node = Node(current_node, node_position)

            # Append the new node to the children list
            children.append(new_node)

        # Loop through children
        for child in children:
            # Child is on the closed list, skip it
            if child in closed_list:
                continue

            # Calculate the child's g, h, and f values
            child.g = current_node.g + 1
            child.h = (
                (child.position[0] - end_node.position[0]) ** 2
                + (child.position[1] - end_node.position[1]) ** 2
            )
            child.f = child.g + child.h

            # Child is already in the open list and having a lower f, skip it
            if len([open_node for open_node in open_list if child == open_node and child.g > open_node.g]) > 0:
                continue

            # Add the child to the open list
            open_list.append(child)


# Example usage
maze = [
    [0, 1, 0, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0],
]

start = (0, 0)  # Start position
end = (4, 4)  # End position

path = astar(maze, start, end)
print("A* Path:", path)
