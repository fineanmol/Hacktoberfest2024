class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> multiSourceQueue;

        // Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                // Check neighboring cells
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    // Check if the neighboring cell is valid and unvisited
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        // Priority queue to prioritize cells with higher safeness factor
        priority_queue<vector<int>> pq;
        // Push starting cell to the priority queue
        pq.push(vector<int>{grid[0][0], 0, 0}); // [maximum_safeness_till_now, x-coordinate, y-coordinate]
        grid[0][0] = -1; // Mark the source cell as visited

        // BFS to find the path with maximum safeness factor
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            // If reached the destination, return safeness factor
            if (curr[1] == n - 1 && curr[2] == n - 1) {
                return curr[0];
            }

            // Explore neighboring cells
            for (auto& d : dir) {
                int di = d[0] + curr[1];
                int dj = d[1] + curr[2];
                if (isValidCell(grid, di, dj) && grid[di][dj] != -1) {
                    // Update safeness factor for the path and mark the cell as visited
                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
                    grid[di][dj] = -1;
                }
            }
        }

        return -1; // No valid path found
    }

private:

    // Directions for moving to neighboring cells: right, left, down, up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Check if a given cell lies within the grid
    bool isValidCell(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }
};