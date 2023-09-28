opened = [] 
closed = [] 

def bfs(graph,start,goal):
    opened.append(start)
    while opened:
        print("open = ",opened)
        print("close = ",closed)
        node = opened.pop(0)
        if node == goal:
            closed.append(node)
            return True
        if node not in closed:
            closed.append(node)
            opened.extend(graph[node])
    return False

graph = {
   'S': ['A', 'B'],
   'A': ['C', 'D'],
   'B': ['F', 'G'],
   'D': [],
   'C': [],
   'F': [],
   'G': []
}

print(bfs(graph,"S","G"))

