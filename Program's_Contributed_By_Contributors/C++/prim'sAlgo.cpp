/*
    Authors Name : Mayuri kolhe
    Date Modified: 1 October, 2022
*/
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 
typedef pair<int, int> iPair;
 
class Graph
{
    int V;

    list< pair<int, int> > *adj;
 
public:
    Graph(int V);
 
    void addEdge(int u, int v, int w);
 
    void primMST();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
void Graph::primMST()
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0;

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;
 
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}
 
int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.primMST();
 
    return 0;
}