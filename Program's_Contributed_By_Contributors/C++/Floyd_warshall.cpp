#include<bits/stdc++.h>
using namespace std;

// Multiple source shortest path - Floyd Warshall Algo

class node{

public:
    int a,b, wt;
    node(int a, int b, int wt){
        this->a = a;
        this->b = b;
        this->wt = wt;
    }
};

class Graph{

    int v;
    vector<vector<pair<int,int>>> adj;
    vector<node> edges;
public:
    Graph(int n){
        this->v = n;
        adj.resize(v);
    }

    void AddEdge(int a, int b,int wt, bool undir){
        adj[a].push_back({b,wt});
        edges.push_back(node(a,b,wt));
        if (undir)
        {
            adj[b].push_back({a,wt});
        }
    }

    void FloydWarshall(){
       
        int distance[v][v]; // 2D adj matrix
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {   
                if (i == j)
                {
                    distance[i][j] = 0;
                }
                else{
                    distance[i][j] = (int)10e4;
                }
            }
        }

        for (auto i: edges)
        {
            int x = i.a;
            int y = i.b;
            int weight = i.wt;

            distance[x][y] = weight;
        }
        
        for (int k = 0; k < v; k++)
        {
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (distance[i][j] > distance[i][k] + distance[k][j])
                    {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }   
                }
            }
        }
        
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {   
                cout<<distance[i][j]<<" ";
            }
            cout<<endl;
        }

        return;
    }
};

int main(){
    
    Graph g(4); 
    g.AddEdge(0, 1, 3, 0); // a, b, wt ,undir
    g.AddEdge(0, 3, 5, 0);
    g.AddEdge(1, 0, 2, 0);
    g.AddEdge(1, 3, 8, 0);
    g.AddEdge(3, 2, 2, 0);
    g.AddEdge(2, 1, 1, 0);

    g.FloydWarshall();

    return 0;
}
