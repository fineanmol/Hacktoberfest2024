vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        dis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto e:adj[node]){
                int adjNode=e[0];
                int weight=e[1];
                if(dist+weight<dis[adjNode]){
                    dis[adjNode]=dist+weight;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
        return dis;
    }

    //single source expansion + used for graphs having positive values and no negative cycles