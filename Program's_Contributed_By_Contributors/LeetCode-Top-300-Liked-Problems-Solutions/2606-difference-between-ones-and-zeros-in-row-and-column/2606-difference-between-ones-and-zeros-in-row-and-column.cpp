class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> onesRow(m, 0);
        vector<int> zerosRow(m, 0);
        vector<int> onesCol(n, 0);
        vector<int> zerosCol(n, 0);
        
        // Calculate row sums and column sums of ones and zeros
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                } else {
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
            }
        }
        
        vector<vector<int>> diff(m, vector<int>(n, 0));
        
        // Calculate the difference matrix based on the formula
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        
        return diff;
    }
    
};