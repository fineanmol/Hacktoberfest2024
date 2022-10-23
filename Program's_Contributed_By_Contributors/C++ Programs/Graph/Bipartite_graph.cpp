#include <bits/stdc++.h>
#define ll long long int
#define f first
#define s second
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;

// TC = O(V+E);
// SC = O(V+E)     +       O(V)     +    O(V)
//    for adjlist        col array      Auxilery space for recursion

int bipartite_DFS(int i, int par, vector<int>adj[], vector<int> &col){

  if(col[i]==-1)col[i] = 1;

  for(auto x: adj[i]){

         if(col[x]==-1){  // not colored yet

            col[x] = 1-col[i];

            if(!bipartite_DFS(x,i,adj,col))  // if one node return false then graph will not remain  bipatitite
              return 0;

         }
         else if(col[x]==col[i]){ // x is visited now check x has different color to it's parent i or not
            return 0;
         }
      }

  return 1;

}

int main(){

  int v,e;cin>>v>>e;

  vector<int>adj[v+1];
  vector<int>vis(v,-1);

  for(int i=0;i<e;i++){
    int a,b;cin>>a>>b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  int flag = 0;

  for(int i=0;i<v;i++){

    if(vis[i]==-1) {// not colored yet

       if(!bipartite_DFS(i,-1,adj,vis)){

        flag = 1;
        break;

       }
    }
  }

  if(flag) //no possible
    cout<<"IMPOSSIBLE\n";

  else{
    for(auto &x: vis)
        cout<<x+1<<" ";
  }

 return 0;
}

