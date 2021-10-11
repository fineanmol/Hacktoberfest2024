#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define INF 9999
typedef pair<int,int> pii;
/*
    Shortest Path : Dijkstra
    limit: *no negtive edge*
    O(E *LogV)
    E : edges
    V : vertexs
*/
vector<pii> Graph[N];
/*
    pii.first = edge
    pii.second = vertex
*/
int Dis[N];
void Init(int n){
    for(int i=0;i<=n;i++) Dis[i]=INF;
}
inline void Add_edge(int v,int u,int e){
    Graph[v].push_back({e,u});
    Graph[u].push_back({e,v});
}
int main(){
    // Intialize Dis[i]= INF
    Init(10);
    // Input
    Add_edge(0, 1, 4);
    Add_edge(0, 7, 8);
    Add_edge(1, 2, 8);
    Add_edge(1, 7, 11);
    Add_edge(2, 3, 7);
    Add_edge(2, 8, 2);
    Add_edge(2, 5, 4);
    Add_edge(3, 4, 9);
    Add_edge(3, 5, 14);
    Add_edge(4, 5, 10);
    Add_edge(5, 6, 2);
    Add_edge(6, 7, 1);
    Add_edge(6, 8, 6);
    Add_edge(7, 8, 7);

    // heap front : min edge
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    // start from 0 , 9 vertexs
    int start=0,V=9;
    Dis[start]=0;
    pq.push({0,start});

    while(pq.size()){
        int cur=pq.top().second;
        pq.pop();

        for(auto i : Graph[cur]){
            int next=i.second, weight=i.first;
            // update if the path is shoter ,and push into pq
            if(Dis[next] > Dis[cur]+ weight){
                Dis[next]= Dis[cur]+ weight;
                pq.push({Dis[next], next});
            }
        }
    }
    cout<<"Vertex  Distance\n";
    for(int i=0;i<V;i++){
        cout<<i<<'\t'<<Dis[i]<<'\n';
    }
    return 0;
}
