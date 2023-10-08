//topological sorting 

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V);
	    for(int i=0;i<V;i++){
	        for(int &e:adj[i]){
	            indegree[e]++;
	        }
	    }
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int size=q.size();
	        for(int i=0;i<size;i++){
	            int temp=q.front();
	            ans.push_back(temp);
	            q.pop();
	            for(int &e:adj[temp]){
	                indegree[e]--;
	                if(indegree[e]==0) q.push(e);
	            }
	        }
	    }
	    return ans;
	}