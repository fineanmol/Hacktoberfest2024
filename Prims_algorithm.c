//Prim's Algo using Adjacency Matrix Representation
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define V 9

int parent[V];
int key[V];
int mstSet[V];

int vertexWithMinKey(int key[],int mstSet[]){
    int vertexWithMinKey;
    int min = INT_MAX;

    for(int i=0;i<V;i++){
        if(mstSet[i] == 0 ){
            if(key[i] < min){
                min = key[i];
                vertexWithMinKey = i;
            }
        }
    }
    return vertexWithMinKey;

}


void printMST(int graph[V][V],int parent[V]){
    printf("Edge \tWeight\n");
    for(int i=0;i<V;i++){
        if(parent[i] != -1){
        printf("%d - %d \t%d \n",parent[i],i,graph[parent[i]][i]);
        }

    }




}
void prims(int graph[V][V]){
    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;  //Included First Vertex in MST

    for(int count = 0;count < V;count++){
        int u = vertexWithMinKey(key,mstSet);
        mstSet[u] = 1;

        for(int i=0;i<V;i++){
            if(graph[u][i] != 0){
                if(graph[u][i] < key[i]){
                    key[i] = graph[u][i];
                    parent[i] = u;
                }
            }
        }

        
    }

    printMST(graph,parent);




}
int main(){
    //GRAPH
    int graph[V][V] = {{0,2,0,6,0},
                    {2,0,3,8,5},
                    {0,3,0,0,7},
                    {6,8,0,0,9},
                    {0,5,7,9,0}};
    prims(graph);
                   
                    
                  
    return 0;
}
