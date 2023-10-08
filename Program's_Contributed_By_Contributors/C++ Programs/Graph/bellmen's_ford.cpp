vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> ans(V,1e8);
        ans[S]=0;
        for(int i=0;i<V;i++){
            for(auto e:edges){
                int u=e[0];
                int v=e[1];
                int weight=e[2];
                if(ans[u]!=1e9 && ans[u]+weight<ans[v]){
                    ans[v]=ans[u]+weight;
                }
            }
        }
        for(auto e:edges){
            int u=e[0];
            int v=e[1];   //for detecting negative cycles
            int weight=e[2];
            if(ans[u]!=1e9 && ans[u]+weight<ans[v]) return {-1};
        }
        return ans;
    }

    //single source expansion + used for graphs having negative values and negative cycles