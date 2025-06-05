#include <bits/stdc++.h>
using namespace std;
 
#define V 5
 
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
 
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0;
    parent[0] = -1;
 
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main()
{
    system ("clear");

    printf("\n| Suchinton                       |");
    printf("\n|---------------------------------|");
    printf("\n| WAP to implement Prims Algo.    |");
    printf("\n|---------------------------------|\n");

    int graph[V][V] = { //    1  2  3  4  5 
                            { 0, 1, 2, 3, 0 },  // 1  
                            { 1, 0, 2, 1, 0 },  // 2
                            { 2, 2, 0, 0, 5 },  // 3
                            { 3, 1, 0, 0, 4 },  // 4
                            { 0, 0, 5, 4, 0 }   // 5
                      };
   
    cout<<"For given graph g:\n ";

    for(int i=0; i<V; i++)
    {
        cout<<"\n | ";
        for(int j=0; j<V; j++)
        {
            cout<<graph[i][j]<<" | ";
        }
        cout<<"\n ";
        for(int n=0; n<V; n++)
            cout<<"----";
    }

    cout<<"\n\n==============================================\n\n";
    primMST(graph);
 
    return 0;
}
