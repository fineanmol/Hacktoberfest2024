opened = [] 
closed = [] 

def dfs(graph,start,goal,opened,closed):
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
            opened = graph[node] + opened
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

print(dfs(graph,"S","G",opened,closed))

