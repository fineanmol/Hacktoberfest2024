class Solution {
private:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>>& heights){
        // Check if the current cell is out of bounds or already visited.
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || vis[r][c])
            return;
        
        vis[r][c] = 1;

        // Define the four possible directions to move.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions) {
            int newRow = r + dir.first;
            int newCol = c + dir.second;

            // Check if the new cell is within bounds and has a higher or equal height.
            if (newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size() &&
                heights[newRow][newCol] >= heights[r][c]) {
                dfs(newRow, newCol, vis, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if (n == 0)
            return {};

        int m = heights[0].size();
        if (m == 0)
            return {};

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        for (int c = 0; c < m; c++) {
            dfs(0, c, pac, heights);
            dfs(n - 1, c, atl, heights);
        }

        for (int r = 0; r < n; r++) {
            dfs(r, 0, pac, heights);
            dfs(r, m - 1, atl, heights);
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
