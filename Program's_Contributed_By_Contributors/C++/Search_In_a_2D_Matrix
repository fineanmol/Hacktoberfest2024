class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<1){
            return false;
        }
        int row =0;
        int col = matrix[0].size()-1;
        while(row<=matrix.size()-1 && col>=0){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]>target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};
