class Solution {
    #define x grid.size()
    #define y grid[0].size()
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int vis[x][y]={0};
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(i==0 || j==0 || i==x-1 || j==y-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r-1>=0 && grid[r-1][c]==1 && vis[r-1][c]==0){
                    q.push({r-1,c});
                    vis[r-1][c]=1;
                }
                if(r+1<x && grid[r+1][c]==1 && vis[r+1][c]==0){
                    q.push({r+1,c});
                    vis[r+1][c]=1;
                }
                if(c-1>=0 && grid[r][c-1]==1 && vis[r][c-1]==0){
                    q.push({r,c-1});
                    vis[r][c-1]=1;
                }
                if(c+1<y && grid[r][c+1]==1 && vis[r][c+1]==0){
                    q.push({r,c+1});
                    vis[r][c+1]=1;
                }
            }
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j]==1 && vis[i][j]==0) ans++;
            }
        }
        return ans;
    }
};