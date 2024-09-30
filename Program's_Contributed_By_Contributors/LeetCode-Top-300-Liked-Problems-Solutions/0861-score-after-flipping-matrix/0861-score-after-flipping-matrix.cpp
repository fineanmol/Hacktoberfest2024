class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Set first column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                // Flip row
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Optimize columns except first column
        for (int j = 1; j < n; j++) {
            int countZero = 0;
            // Count zeros
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) {
                    countZero++;
                }
            }
            // Flip the column if there are more zeros for better score
            if (countZero > m - countZero) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Calculate the final score considering bit positions
        int score = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Left shift bit by place value of column to find column contribution
                int columnScore = grid[i][j] << (n - j - 1);
                // Add contribution to score
                score += columnScore; 
            }
        }

        // return final result
        return score;
    }
};