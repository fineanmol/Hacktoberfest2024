class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    int t1 = 0;
                    int t2 = 0;
                    for (int k = 0; k < m; ++k)
                        t1 += mat[k][j];
                    for (int k = 0; k < n; ++k)
                        t2 += mat[i][k];
                    if (t1 == 1 && t2 == 1)
                        cnt++;
                }
            }
        }
        
        return cnt;
    }
};
