// Made by Sameer Aggrawal

#include<bits/stdc++.h>
using namespace std;

void Dijikstra(int src,int n,vector<pair<int,int>> adj[])
{
    vector<int> distance(n+1,INT_MAX);
    
    int i;

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

    distance[src]=0;
    pq.push({0,src}); // dist,from

    while(!pq.empty())
    {
        int d = pq.top().first;
        int prevNode = pq.top().second;

        pq.pop();

        for(auto it: adj[prevNode])
        {
            if(distance[it.first]>d+it.second) // prevDistance+current edge wt is less than current node wt, then update the current node wt
            {
                distance[it.first]=d+it.second;
                pq.push({distance[it.first],it.first});
            }
        }
    }

    for(i=1;i<=n;i++) cout<<distance[i]<<" ";

    // Time Complexity - O((V+E)*log(V)) 
    // Space Complexity - O(V) + O(V) (distance + priority queue)
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,edges,i,a,b,wt;
    cin>>n>>edges;

    vector<pair<int,int>> adj[n+1];

    for(i=0;i<edges;i++)
    {
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    Dijikstra(1,n,adj);

    return 0;
}
