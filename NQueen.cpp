#include <iostream>
using namespace std;
#define N 8

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isValid(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++) // check whether there is queen in the left or not
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) // check whether there is queen in the left upper diagonal or not
            return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) // check whether there is queen in the left lower diagonal or not
            return false;
    return true;
}

bool solveNQueen(int board[N][N], int col)
{
    if (col >= N) // when N queens are placed successfully
        return true;
    for (int i = 0; i < N; i++)
    { // for each row, check placing of queen is possible or not
        if (isValid(board, i, col))
        {
            board[i][col] = 1;               // if validate, place the queen at place (i, col)
            if (solveNQueen(board, col + 1)) // Go for the other columns recursively
                return true;

            board[i][col] = 0; // When no place is vacant remove that queen
        }
    }
    return false; // when no possible order is found
}

bool checkSolution()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0; // set all elements to 0

    if (solveNQueen(board, 0) == false)
    { // starting from 0th column
        cout << "Solution does not exist";
        return false;
    }
    printBoard(board);
    return true;
}

int main()
{
    checkSolution();
}
