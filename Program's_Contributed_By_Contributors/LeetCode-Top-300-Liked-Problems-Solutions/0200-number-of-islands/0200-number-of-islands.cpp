class Solution {
private:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse in the neighbours and mark them if it's a land
            int dr[] = {1, 0, -1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++) {
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int num_islands = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    num_islands++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return num_islands;
    }
};
