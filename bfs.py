# Declare BFS function
def bfs(graph, start):
    visited = set()  # Set to keep track of visited nodes
    queue = []  # List used as a queue for BFS

    visited.add(start)
    queue.append(start)

    while queue:
        node = queue.pop(0)  # Dequeue a vertex from the front of the list
        print(node, end=' ')

        # Get all adjacent vertices of the dequeued vertex that haven't been visited
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)


# Example usage:

# Define an example graph as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

print("Breadth-First Traversal starting from 'A':")
bfs(graph, 'A')
