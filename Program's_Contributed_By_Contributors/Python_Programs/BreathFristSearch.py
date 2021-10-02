from collections import deque

def bfs(graph,start_node,visited):
    queue=deque([start_node])
    visited[ord(start_node)-64]=True
    while queue:
        node=queue.popleft()
        print(node,end=" ")
        for i in graph[node]:
            if not visited[ord(i)-64]:
                queue.append(i)
                visited(ord(i)-64)=True

# Data Example
graph = {
    0:[],
    'A': ['B'],
    'B': ['A', 'C', 'H'],
    'C': ['B', 'D'],
    'D': ['C', 'E', 'G'],
    'E': ['D', 'F'],
    'F': ['E'],
    'G': ['D'],
    'H': ['B', 'I', 'J', 'M'],
    'I': ['H'],
    'J': ['H', 'K'],
    'K': ['J', 'L'],
    'L': ['K'],
    'M': ['H']
}

visited_bfs=[False]*(len(graph))

bfs(graph,'A',visited_bfs)
print()