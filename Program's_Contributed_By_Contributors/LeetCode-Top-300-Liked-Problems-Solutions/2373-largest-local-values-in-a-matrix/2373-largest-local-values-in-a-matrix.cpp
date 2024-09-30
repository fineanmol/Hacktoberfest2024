class Solution {
private:
    // Return the maximum values in the 3 x 3 matrix with top-left as (x, y).
    int findMax(vector<vector<int>>& grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        
        return maxElement;
    }
public: 
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = grid.size();
        
        vector<vector<int>> maxLocal(N - 2, vector<int>(N - 2, 0));
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 2; j++) {
                maxLocal[i][j] = findMax(grid, i, j);
            }
        }
        
        return maxLocal;
    }
};
