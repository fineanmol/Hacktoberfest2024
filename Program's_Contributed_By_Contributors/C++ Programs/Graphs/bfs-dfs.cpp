//depth first traversal where st is starting vertice and adj is adjacency list

void dfs(vector<int> adj[],int st,vector<bool>& vis,vector<int>& ans){
    if(!vis[st])
    ans.push_back(st);
    vis[st]=true;
    for(int &e: adj[st]){
        if(vis[e]) continue;
        dfs(adj,e,vis,ans);
    }
    return;
}

// breadth first traversal where V is vertices and adj is adjacency list

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    queue<int> q;
    vector<int> level;
    vector<bool> vis(V);
    q.push(0);
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
    return level;
}