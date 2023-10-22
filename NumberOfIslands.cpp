class Solution {
public:
    int ans=0;
    void dfs(vector<vector<char>>& grid,int i,int j){
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
       return;
       grid[i][j]='0';
       dfs(grid,i+1,j);
       dfs(grid,i,j+1);
       dfs(grid,i-1,j);
       dfs(grid,i,j-1);
       return;
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1')
                ans++,dfs(grid,i,j);
            }
        }
        return ans;
    }
};
