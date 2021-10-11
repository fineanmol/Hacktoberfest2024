// Leetcode Problem No: 36. Valid Sudoku https://leetcode.com/problems/valid-sudoku/
#define N 9
class Solution {
public:

    bool checkIfSudokuValid(vector<vector<char>>& board, int x, int y) {

        if(y==N) {
            x++;
            y=0;
        }

        if (x==N) 
            return true;  

        if (board[x][y]=='.')
            return checkIfSudokuValid(board, x, y+1);

        char curr = board[x][y];

        for (int i=0; i<N; i++) {
            if (y!=i && board[x][i]!='.' && board[x][i]==curr)
                return false;
            if (x!=i && board[i][y]!='.' && board[i][y]==curr)
                return false;
        }

        int r = (x/3)*3, c=(y/3)*3;

        for (int i=r; i<r+3; i++) {
            for (int j=c; j<c+3; j++) {
                if ( (i!=x || j!=y) && board[i][j]==curr) {
                    return false;
                }

            }
        }

        return checkIfSudokuValid(board, x, y+1);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkIfSudokuValid(board, 0, 0);
    }
};
