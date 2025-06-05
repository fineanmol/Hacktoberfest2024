class Solution {
public:
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int maxGold = 0;

    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
        
        int curr = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = curr;

        for (int i = 0; i < 4; i++) {
            int newX = x + roww[i];
            int newY = y + coll[i];
            localMaxGold = max(localMaxGold, curr + dfs(grid, newX, newY, n, m));
        }

        grid[x][y] = curr;
        return localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};