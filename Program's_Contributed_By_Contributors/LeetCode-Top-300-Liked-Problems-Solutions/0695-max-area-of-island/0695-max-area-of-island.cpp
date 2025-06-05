class Solution {
private:
    void dfs(int r, int c, int n, int m, vector<vector<int>> &grid, int &cnt){
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
            return;

        grid[r][c] = 0;
        cnt += 1;

        dfs(r + 1, c, n, m, grid, cnt);
        dfs(r - 1, c, n, m, grid, cnt);
        dfs(r, c - 1, n, m, grid, cnt);
        dfs(r, c + 1, n, m, grid, cnt);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxArea = 0, cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cnt = 0;
                if(grid[i][j] == 1){
                    dfs(i, j, n, m, grid, cnt);
                }
                maxArea = max(maxArea, cnt);
            }
        }

        return maxArea;
    }
};