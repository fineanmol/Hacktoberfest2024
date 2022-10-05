#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<pair<int,int>> adj[m];
    for(int i =0;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int> key(m,INT_MAX),parent(m,-1),mst(m,false);
    key[0]=0;
    parent[0]=-1;

    for(int i =0;i<m-1;i++){
        int mini=INT_MAX,u;
        for(int i =0;i<m;i++){
            if(key[i]<mini&&mst[i]==false){
                mini = key[i];
                u = i;
            }
        }
        mst[u]=true;
        for(auto it: adj[u]){
            int v = it.first;
            int weight = it.second;
            if(mst[v]==false&&weight<key[v]){
                parent[v] = u;
                key[v]=weight;
            }
        }
    }

    for(int i =0;i<m;i++){
        cout<<parent[i]<<" -> "<<i<<endl;
    }
    return 0;
}
