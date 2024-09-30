class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        
        // traverse all its neighbours
        for(auto it : adj[node]){
            if(!vis[it]) 
                dfs(it, adj, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        int count = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count += 1;
                dfs(i, adj, vis);
            }
        }
        return count;

    }
};