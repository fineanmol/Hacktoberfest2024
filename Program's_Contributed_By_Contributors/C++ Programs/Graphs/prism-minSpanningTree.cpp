int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum=0;
        vector<int> vis(V);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,0});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=dis;
            for(auto ele:adj[node]){
                if(!vis[ele[0]]){
                    pq.push({ele[1],ele[0]});
                }
            }
        }
        return sum;
    }