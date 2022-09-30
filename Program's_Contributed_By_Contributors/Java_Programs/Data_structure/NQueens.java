package backtracking;

import java.util.Scanner;

public class NQueens {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Solution.placeNQueens(n);
    }
}

class Solution {
    public static void placeNQueens(int n){
        int[][] board = new int[n][n];
        placeQueen(board, 0, n);
    }

    private static void placeQueen(int[][] board, int row, int n){
        if (row == n){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        }
        for (int j = 0; j < n; j++){
            if (isBoardSafe(board, row, j)){
                board[row][j] = 1;
                placeQueen(board, row + 1, n);
                board[row][j] = 0;
            }
        }
    }

    private static boolean isBoardSafe(int[][] board, int row, int col){
        int n = board.length;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
            if (board[i][j] == 1){
                return false;
            }
        }
        for (int i = row + 1, j = col + 1; i < 0 && j < 0; i++,j++){
            if (board[i][j] == 1){
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j <n; i--,j++){
            if (board[i][j] == 1){
                return false;
            }
        }
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++,j--){
            if (board[i][j] == 1){
                return false;
            }
        }
        for (int i = row - 1; i >= 0; i--){
            if (board[i][col] == 1){
                return false;
            }
        }
        for (int i = row + 1; i < n; i++){
            if (board[i][col] == 1){
                return false;
            }
        }
        return true;
    }
}
