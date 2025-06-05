import sys
def floyd_warshall(graph):
    n = len(graph)
    # stepping loop
    for k in range(n):
        # outer loop
        for i in range(n):
            # inner loop
            for j in range(n):
                # replace direct path with path through k if direct path is longer
                if i != j:
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
                else:
                    graph[i][j] = 0
    # print complete graph in a pretty manner
    for row in graph:
        print(row)
        
        
A = [[sys.maxsize,8,sys.maxsize,1],
     [sys.maxsize,sys.maxsize,1,sys.maxsize],
     [4,sys.maxsize,sys.maxsize,sys.maxsize],
     [sys.maxsize,2,9,sys.maxsize]]
floyd_warshall(A)
