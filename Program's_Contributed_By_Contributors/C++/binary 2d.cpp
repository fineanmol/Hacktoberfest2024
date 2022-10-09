class Solution {
public:
    bool Mat(vector<vector<int>>& matr, int tar) {
        int rows = matr.size(),
			cols = matr[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matr[row][col];
            if (cur == tar) return true;
            if (tar > cur) row++;
            else col--;
        }
        
        return false;
    }
};
