#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // All queens are placed successfully
        return true;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;  // Place the queen

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing the queen in board[row][col] doesn't lead to a solution,
            // then backtrack and try the next column
            board[row][col] = 0;  // Backtrack
        }
    }

    // If no queen can be placed in this row, return false
    return false;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        // Print the solution
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
