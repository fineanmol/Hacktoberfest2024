#include <bits/stdc++.h>
using namespace std;
bool bipartiteDFS(int s,int color[],vector<int> adj[])
{
if(color[s]==-1)
color[s]=1;
for(auto i: adj[s])
{
    if(color[i]==-1)
    {
        color[i]=1-color[s];
        if(!bipartiteDFS(i,color,adj));
        return false;
    }
    else if(color[i]==color[s])
    return false;
}
return true;
}

bool checkBipartite(vector<int> adj[],int n)
{
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartiteDFS(i,color,adj));
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkBipartite(adj,n))
    cout<<"The given graph is a Bipartite Graph";
    else
    cout<<"The given graph is not a Bipartite Graph";
}