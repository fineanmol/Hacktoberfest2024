//no of provinces problem can be also used for traversal of graph having components

void bfs(int V,vector<int> adj[],vector<bool>& vis,int st) {
    queue<int> q;
    vector<int> level;
    q.push(st);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            level.push_back(q.front());
            vis[q.front()]=true;
            for(int &e: adj[q.front()]){
                if(!vis[e]){
                    q.push(e);
                    vis[e]=true;
                }
            }
            q.pop();
        }
    }
    return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> edges[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    edges[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<bool> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(V,edges,vis,i);
                cnt++;
            }
        }
        return cnt;
    }