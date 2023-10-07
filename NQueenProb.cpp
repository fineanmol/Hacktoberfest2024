#include <bits/stdc++.h>
using namespace std;
bool canPass(int board[][20], int n, int i, int j)
{
    for (int x = 0; x < i; x++)
    {
        if (board[x][j] == 1)
        {
            return false;
        }
    }
    int x = i, y = j;
    while (x >= 0 and y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = i, y = j;
    while (x >= 0 and y < n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
void printBoard(int board[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool NQueenBoard(int board[][20], int n, int i)
{

    if (i == n)
    {
        printBoard(board, n);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPass(board, n, i, j))
        {
            board[i][j] = 1;
            bool sol = NQueenBoard(board, n, i + 1);
            if (sol)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int board[20][20] = {};
    int n;
    cin >> n;
    NQueenBoard(board,n,0);
}