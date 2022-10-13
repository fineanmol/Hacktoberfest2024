#include<iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;

void bfs(int i,vector<int> adj[],vector<int> &vis,vector<int>& ans)
{
    queue<int> q;

    q.push(i);
    vis[i]=1;
    while(!q.empty())
    {
        int tp=q.front();
        ans.push_back(tp);
        q.pop();
        for(int j=0;j<adj[tp].size();j++)
        {
            //cout<<"##"<<adj[tp][j]<<"##"<<endl;
            if (!vis[adj[tp][j]])
            {
                q.push(adj[tp][j]);
                vis[adj[tp][j]] = 1;
            }
        }
    }
}

void dfs(int i,vector<int>adj[],vector<int> &vis, vector<int>&ans)
{
    ans.push_back(i);
    vis[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!vis[adj[i][j]])
        {
            dfs(adj[i][j],adj,vis,ans);
        }
    }
}

bool cyclebfs(int i,vector<int> adj[],vector<int> &vis)
{
    queue<pair<int,int>> q;

    q.push({i,-1});
    vis[i]=1;
    while(!q.empty())
    {
        int tp=q.front().first;
        int parent =q.front().second;
        q.pop();
        for(int j=0;j<adj[tp].size();j++)
        {
            //cout<<"##"<<adj[tp][j]<<"##"<<parent<<endl;
            if (!vis[adj[tp][j]])
            {
                q.push({adj[tp][j],tp});
                vis[adj[tp][j]] = 1;
            }
            else if (adj[tp][j]!=parent)
            {
                return true;
            }

        }
    }
    return false;
}

bool cycledfs(int i,vector<int>adj[],vector<int> &vis,int par)
{
    //int parent=i;
    //ans.push_back(i);
    vis[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(!vis[adj[i][j]])
        {
            par =i;
            cycledfs(adj[i][j],adj,vis,par);
        }
        else if(par!=adj[i][j])
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<int> adj[],vector<int> &vis,int n)
{
    vector<int> ans; // Only so that we dont need to change the bfs/dfs function no use in cycle detection
    for(int i=1;i<n+1;i++)
    {
        if(!vis[i])
        {
            //if(cyclebfs(i,adj,vis))
            if(cycledfs(i,adj,vis,-1))
            return true;
        }
    }
    return false;
}

int shortestdistance(int n,int st,int tar, vector<int> adj[],vector<int>&vis)
{
    int d=0;
    vector<int> dist(n,INT16_MAX);
    queue<int> q;
    q.push(st);
    dist[st]=d;
    while(!q.empty())
    {
        d++;
        int node=q.front();
        q.pop();
        for(int j=0;j<adj[node].size();j++)
        {
            if(!vis[adj[node][j]])
            {
                q.push(adj[node][j]);
                vis[adj[node][j]]=1;
                if(dist[adj[node][j]]>d) dist[adj[node][j]]=d;
            }
        }
    }
    return dist[tar];

}

bool bipertile(vector<int>adj[])
{

}

int main()
{
    int n,e; cout<<"\n Enter number of nodes and edges: ";
    cin>>n>>e;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);
    vector<int> ans;

    //UNdirected adj list
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    //For detecting shortest dist
    // int tar,st;
    // cout<<"\n Enter start and target : ";
    // cin>>st>>tar;
    // int dist=shortestdistance(n+1 ,st,tar,adj,vis);
    // if(dist==INT16_MAX) cout<<"Infinite";
    // else cout<<dist;

    //For detecting cycle
    // if(isCycle(adj,vis,n))
    // cout<<"TRUE";
    // else cout<<"FALSE";

    //For printing adj list
    // for(int i=1;i<n+1;i++)
    // {
    //     cout<<i;
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         cout<<" -> "<<adj[i][j];
    //     }
    //     cout<<"\n";
    // }

    //For calling dfs/bfs
    // for(int i=1;i<n+1;i++)
    // {
    //     if(!vis[i])
    //     //bfs(i, adj,vis,ans);
    //     //dfs(i,adj,vis,ans);
    // }

    // For printing bsf/dfs traversal answer
    // for(int it=0;it<ans.size();it++)
    // {
    //     cout<<ans[it]<<" ";
    // }
    return 0;
}