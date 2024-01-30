import sys

def dijkstra(graph, start):
    # Number of vertices in the graph
    num_vertices = len(graph)
    
    # Initialize distance and visited lists
    distance = [sys.maxsize] * num_vertices
    distance[start] = 0
    visited = [False] * num_vertices

    for _ in range(num_vertices):
        # Find the vertex with the minimum distance
        min_distance = sys.maxsize
        min_index = -1
        for v in range(num_vertices):
            if not visited[v] and distance[v] < min_distance:
                min_distance = distance[v]
                min_index = v

        # Mark the selected vertex as visited
        visited[min_index] = True

        # Update distance values for adjacent vertices
        for v in range(num_vertices):
            if not visited[v] and graph[min_index][v] > 0:
                if distance[min_index] + graph[min_index][v] < distance[v]:
                    distance[v] = distance[min_index] + graph[min_index][v]

    return distance

# Example usage
if __name__ == "__main__":
    graph = [
        [0, 2, 4, 0, 0, 0],
        [0, 0, 2, 4, 2, 0],
        [0, 0, 0, 0, 3, 0],
        [0, 0, 0, 0, 0, 2],
        [0, 0, 0, 0, 0, 3],
        [0, 0, 0, 0, 0, 0]
    ]

    start_vertex = 0
    shortest_distances = dijkstra(graph, start_vertex)
    
    for i, distance in enumerate(shortest_distances):
        print(f"Shortest distance from vertex {start_vertex} to vertex {i}: {distance}")
      
# It was contrbuted by Ayush Morbar
#https://github.com/ayushmorbar
