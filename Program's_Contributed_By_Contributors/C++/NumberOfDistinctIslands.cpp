void dfs(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>> &v){
        if(i<0 or j<0 or i == grid.size() or j == grid[0].size() or !grid[i][j]) return;
        v.push_back({i,j});
        grid[i][j]=0;
        dfs(grid,i+1,j,v);
        dfs(grid,i,j+1,v);
        dfs(grid,i-1,j,v);
        dfs(grid,i,j-1,v);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    vector<pair<int,int>> v;
                    dfs(grid,i,j,v);
                    auto t=v[0];
                    for(auto &k:v){
                        k.first-=t.first;
                        k.second-=t.second;
                    }
                    if(s.find(v) == s.end()) s.insert(v);
                }
            }
        }
        return s.size();
    }
