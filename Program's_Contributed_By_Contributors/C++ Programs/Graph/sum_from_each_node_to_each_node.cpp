#include<bits/stdc++.h>
#define ll long long int
#define f first
#define s second
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;


int BFS(int u, int v,int V, vector<int>adj[], vector<int>&arr){
    
    vector<int>vis(V+1,0),parent(V+1,-1);
    
    int ans=0;
    queue<pair<int,int>>q;
   
    q.push({u,-1});

    vis[u] = 1;

    while(!q.empty()){

        int node = q.front().f, par = q.front().s;
        
        q.pop();

        if(node==v){
            int ans = 0;
            while(v != -1){
                // cout<<v<<" ";
                ans += arr[v-1];
                v = parent[v];
            }
            return ans;
        }

        for(auto &nbr : adj[node]){

            if(nbr != par){
                if(!vis[nbr]){
                    q.push({nbr,node});
                    parent[nbr] = node;
                    vis[nbr] = 1;
                }
            }
        }        
    }
}

int main(){

  int V,e,a,b;cin>>V>>e;
  vector<int>adj[V+1];

  while(e--){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int>arr(V);
  for(auto &x: arr) cin>>x;

  int q;cin>>q;
// cout<<q<<" ";
  while(q--){
    int u,v;cin>>u>>v;
    vector<int>vis(V+1,0);
    cout<<BFS(u,v,V,adj,arr)<<endl;
  }

}