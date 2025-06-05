from collections import defaultdict as dd  
  
class Graph:  
    
    # Constructing a list  
    def __init__(self):  
    
        # default dictionary to store graph  
        self.graph = dd(list)  
    
    # defining function which will add edge to the graph  
    def addEdgetoGraph(self, x, y):  
        self.graph[x].append(y)  
    
    # defining function to print BFS traverse  
    def BFSearch(self, n):  
    
        # Initially marking all vertices as not visited  
        visited_vertices = ( len(self.graph ))*[False]  
    
        # creating a queue for visited vertices  
        queue = []  
    
        # setting source node as visited and adding it to the queue  
        visited_vertices[n] = True  
        queue.append(n)  
          
    
        while queue:  
    
            # popping the element from the queue which is printed  
            n = queue.pop(0)  
            print (n, end = " ")  
    
            # getting vertices adjacent to the vertex n which is dequed.   
            for v in self.graph[ n ]:  
                if visited_vertices[v] == False:  
                    queue.append(v)  
                    visited_vertices[v] = True  
