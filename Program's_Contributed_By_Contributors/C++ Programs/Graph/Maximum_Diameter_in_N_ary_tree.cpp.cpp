#include<bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f first
#define s second
#define pb push_back 
#define ll long long
int MOD = 1e9+7;

int ans=0;
int DFS(int i,int par,vector<int>adj[]){

    int mx  = 0, premax = 0;
    for(auto x: adj[i]){
        if(x != par){
            int height = DFS(x,i,adj);
            if(mx < height )
                premax = mx, mx = height;
            else if(premax < height)
                premax = height;
        }
    }
     ans = max(ans, mx+premax+1);
    return 1 + mx;
}
int main(){

    int n;cin>>n; // number of nodes
    vector<int>adj[n+1];

    for(int i=0;i<n-1;i++){
       int u, v; cin>>v>>u;
       --v,--u;
       adj[v].emplace_back(u);
       adj[u].emplace_back(v);
    }

    DFS(0,-1,adj);
    cout<<ans;
}

/*

Input
11         // numbr of vertices
1 2        // next n-1 lines of edges connected u to v
1 7
1 6 
1 4 
1 5
2 10
10 11
2 3
7 8 
8 9

output 
7