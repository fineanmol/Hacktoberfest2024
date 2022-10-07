// Bellman Ford Algorithm in C++

#include <bits/stdc++.h>


struct Edge {
  int u; 
  int v;  
  int w; 
};


struct Graph {
  int V;        
  int E;        
  struct Edge* edge;  
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = new Graph;
  graph->V = V; 
  graph->E = E;  

  
  graph->edge = new Edge[E];
  return graph;
}


void printArr(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void BellmanFord(struct Graph* graph, int u) {
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;

  
  dist[u] = 0;

  
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
     
      int u = graph->edge[j].u;
      int v = graph->edge[j].v;
      int w = graph->edge[j].w;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
    }
  }


  for (int i = 0; i < E; i++) {
    int u = graph->edge[i].u;
    int v = graph->edge[i].v;
    int w = graph->edge[i].w;
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      printf("Graph contains negative w cycle");
      return;
    }
  }

  
  printArr(dist, V);

  return;
}

int main() {
  
  int V = 5;  
  int E = 8;  

 
  struct Graph* graph = createGraph(V, E);

  graph->edge[0].u = 0;
  graph->edge[0].v = 1;
  graph->edge[0].w = 5;

  graph->edge[1].u = 0;
  graph->edge[1].v = 2;
  graph->edge[1].w = 4;

  graph->edge[2].u = 1;
  graph->edge[2].v = 3;
  graph->edge[2].w = 3;

  graph->edge[3].u = 2;
  graph->edge[3].v = 1;
  graph->edge[3].w = 6;

  graph->edge[4].u = 3;
  graph->edge[4].v = 2;
  graph->edge[4].w = 2;

  BellmanFord(graph, 0); 

  return 0;
}
