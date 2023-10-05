class Solution {
public:
     vector<int>row_={-1,0,1,0};
    vector<int>col_={0,1,0,-1};
    int m,n;

    bool isvalid(int row, int col) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

    int  bfs(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&vis){
          vis[row][col]=1;
          queue<pair<int,int>>q;
          q.push({row,col});
          int count=1;
          while(!q.empty()){
              auto i=q.front();
              int r=i.first;
              int c=i.second;

              q.pop();

              for(int j=0;j<4;j++){
                  int rv=r+row_[j];
                  int cv=c+col_[j];
                  if(isvalid(rv,cv)){
                      if(!vis[rv][cv] && grid[rv][cv]==1){
                         vis[rv][cv]=1;
                         q.push({rv,cv});
                         count++;
                      }
                  }
              }
          }
          return count;
    }



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
         n=grid[0].size();

         vector<vector<int>>vis(m,vector<int>(n,0));

        int ans=0;

         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(grid[i][j]==1 && !vis[i][j]){

                    int v= bfs(grid,i,j,vis);
                    ans=max(v,ans);
                 }
             }
         }
         return ans;
    }
};