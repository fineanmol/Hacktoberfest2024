// Implementation of Single Shortest path for a graph using Belman ford algorithm. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
struct Edge
{

    int source, destination, weight;
};
 

struct Graph
{
    int V, E; 
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph)); 
    graph->V = V;   //assigning values to structure elements that taken form user.
 
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
    return graph;
}
 
void FinalSolution(int dist[], int n)
{

    printf("\nVertex\tDistance from Source Vertex\n");
    int i;
 
    for (i = 0; i < n; ++i){
printf("%d \t\t %d\n", i, dist[i]);
}
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
 
    int E = graph->E;
 
    int StoreDistance[V];
 
    int i,j;
 
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;
 
    
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
 
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("This graph contains negative edge cycle\n");
    }
 
    FinalSolution(StoreDistance, V);
 
    return;
}
 
int main()
{
    int V,E,S;  //V = no.of Vertices, E = no.of Edges, S is source vertex
 
printf("Enter number of vertices in graph\n");
    scanf("%d",&V);
 
printf("Enter number of edges in graph\n");
    scanf("%d",&E);
 
printf("Enter your source vertex number\n");
scanf("%d",&S);
 
    struct Graph* graph = createGraph(V, E);    //calling the function to allocate space to these many vertices and edges
 
    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S); 
    return 0;
}
