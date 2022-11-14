import java.util.*;
public class SudokuSolver {
    public static void main(String[] args) {
                        //  0   1   2   3   4   5   6   7   8
        char[][] board = {{'5','3','.','.','7','.','.','.','.'},  // 0
                          {'6','.','.','1','9','5','.','.','.'},  // 1
                          {'.','9','8','.','.','.','.','6','.'},  // 2
                          {'8','.','.','.','6','.','.','.','3'},  // 3
                          {'4','.','.','8','.','3','.','.','1'},  // 4
                          {'7','.','.','.','2','.','.','.','6'},  // 5
                          {'.','6','.','.','.','.','2','8','.'},  // 6
                          {'.','.','.','4','1','9','.','.','5'},  // 7
                          {'.','.','.','.','8','.','.','7','9'}}; // 8
        
        if (solve(board, 0, 0)) {
            System.out.println(Arrays.deepToString(board));
        } else {
            System.out.println("Cannot solve");
        }
    }

    static boolean solve(char[][] board, int row, int col) {
        int n = board.length;
        if (col == n) {     // go to next row
            col = 0;
            row += 1;
        }
        
        while (row < n && col < n && board[row][col] != '.') {  // find empty spot
            col++;
            if (col == n) {
                col = 0;
                row++;
            }
        }
        if (row == n) {     // sudoku complete
            return true;
        }
        
        for (int number = 1; number <= 9; number++) {
            char num = (char) ('0' + number);
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                if (solve(board, row, col + 1)) {
                    return true;
                } else {
                    // backtrack
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    
    static boolean isSafe(char[][] board, int row, int col, char num) {
        // check row
        for (int i = 0; i < board.length; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        
        // check column
        for (char[] nums : board) {
            if (nums[col] == num) {
                return false;
            }
        }
        
        // check in 3x3 sub-boxes
        int rowStart = row - row % 3;
        int colStart = col - col % 3;
        for (int r = rowStart; r < rowStart + 3; r++) {
            for (int c = colStart; c < colStart + 3; c++) {
                if (board[r][c] == num) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
