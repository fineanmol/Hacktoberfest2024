#include <bits/stdc++.h>
using namespace std;
bool isValidPosition(vector<vector<char>> &board, int row, int col, int digit)
{
    // row
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][col] == '0' + digit)
            return false;
    }
    // column
    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] == '0' + digit)
            return false;
    }
    // this is for the 3 x 3 matrix
    int startRow = row - (row % 3); // its finding the row index from where its 3x3 matrix is starting
    int startCol = col - (col % 3); // its finding the column index from where its 3x3 matrix is starting
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == '0' + digit)
                return false;
        }
    }
    return true; // if any of the condition hit inside these 3 loops
}
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (int d = 1; d <= 9; d++)
                {
                    if (isValidPosition(board, i, j, d)) // if its valid then
                    {
                        board[i][j] = '0' + d; // put the digit and solve for further
                        if (solve(board))      // call again for further solve
                        {
                            return true; // if further call returns true that mean the digit
                            // we have placed is right and return true
                        }
                        else // change board digit to its original position
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false; // after putting all value from 1 to 9 but still is not solve then return false
            }
        }
    }
    return true; // we came here only when board all cells is filled with digit
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    for (auto row : board)
    {
        for (auto cell : row)
            cout << cell << " ";
        cout << endl;
    }
    return 0;
}
