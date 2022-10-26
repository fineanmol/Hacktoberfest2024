from queue import PriorityQueue

class Graph:
    def __init__(self, vertices):
        self.v = vertices
        self.edges = [[-1 for i in range(vertices)] 
                      for j in range(vertices)]
        self.visited = []
    def add_edge(self, u, v, weight):
        self.edges[u][v] = weight
        self.edges[v][u] = weight

def dijkstra(graph, first):
    D = {v:float('inf') for v in range(graph.v)}
    D[0]=0
    D[first] = 0
    pq = PriorityQueue()
    pq.put((0, first))

    while not pq.empty():
        (dist, current_vertex) = pq.get()
        graph.visited.append(current_vertex)

        for near_node in range(graph.v):
            if graph.edges[current_vertex][near_node] != -1:
                distance = graph.edges[current_vertex][near_node]
                if near_node not in graph.visited:
                    old_cost = D[near_node]
                    new_cost = D[current_vertex] + distance
                    if new_cost < old_cost:
                        pq.put((new_cost, near_node))
                        D[near_node] = new_cost
    return D


g = Graph(7)
g.add_edge(1, 2, 2)
g.add_edge(1, 3, 4)
g.add_edge(2, 3, 1)
g.add_edge(2, 4, 7)
g.add_edge(3, 5, 3)
g.add_edge(5, 4, 2)
g.add_edge(6, 4, 1)
g.add_edge(6, 5, 5)

D = dijkstra(g, 1)
dist=len(D)
for node in range(1,dist):
    print("Distance from Node 1 to node", node, "is", D[node])
  
  