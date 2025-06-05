class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize the distances for cells containing 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    distances[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Possible directions to move: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            for (const auto& dir : directions) {
                int newRow = curr.first + dir.first;
                int newCol = curr.second + dir.second;
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (distances[newRow][newCol] > distances[curr.first][curr.second] + 1) {
                        distances[newRow][newCol] = distances[curr.first][curr.second] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return distances;
    }
};
