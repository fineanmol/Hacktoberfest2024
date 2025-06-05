#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//first we will creat a visited array and initialize it to false using memset
    
void dfs(int startvertex , int V , vector<int> adj[] , bool visited[])
{
    
    visited[startvertex] = true;
    cout << startvertex << " ";
    
    vector <int> adjlist  = adj[startvertex];
 
        for(auto i : adjlist)
        {
            if(!visited[i])
            {
                dfs(i , 5 , adj , visited);
            }
        }
}


int main()
{
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);
    
    bool visited[5];
    memset(visited , false , sizeof visited);
    dfs(0, 5 , adj , visited);
    
}
    
