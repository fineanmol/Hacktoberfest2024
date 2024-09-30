class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(n, 0);
	    
	    for(int i = 0; i < n; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < n; i++){
	        if(indegree[i] == 0){
	             q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) 
	                q.push(it);
	        }
	    }

        reverse(topo.begin(), topo.end());
	    
	    if (topo.size() == n) return topo;
        return {};
    }
};