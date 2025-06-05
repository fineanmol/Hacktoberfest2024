class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> t(m, vector<int>(n, 0)); // transpose matrix, so n = m & m = n
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){  
                t[j][i] = matrix[i][j];
            }
        }
        return t;
    }
};
