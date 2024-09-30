class Solution {
public:
    bool dfs(int s, int d, vector<vector<int>> &edges, vector<int> &vis){
        if(s == d)
            return true;
        
        vis[s] = 1;
        for(int n : edges[s]){
            if(!vis[n]){
                if(dfs(n, d, edges, vis))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(source, destination, adj, vis);
    }
};