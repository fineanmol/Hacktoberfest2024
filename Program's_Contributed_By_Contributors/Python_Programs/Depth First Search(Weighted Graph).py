# Using a Python dictionary to act as an adjacency list
graph = {
  'A' : [[8,'B'],[5,'E']],
  'B' : [[2,'D'],[1,'C']],
  'E' : [[1,'G']],
  'G' : [],
  'C' : [[3,'F']],
  'F' : [[4,'G']],
  'D' : [[3,'E']]
  
}  
print("The Path Is = ",end = " ")
found=0
visited = set()
def dfs(visited, graph, node,goal):
    global found
    if found==1:
        return
    elif node not in visited:
        print(node,end=" ")
        if node ==goal:
            print ("\n***Goal Found***")
            found=1 
            return
        visited.add(node)
        templist=graph[node]
        templist.sort()
        for neighbour in templist:
            if len(neighbour)>0:
                dfs(visited, graph,neighbour[1],'G')
dfs(visited, graph, 'A','G')