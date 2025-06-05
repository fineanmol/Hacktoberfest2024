#include <iostream>
#include <vector>
using namespace std;
bool canWePlace(vector<vector<char>> &board, int r, int c, char n)
{
  // Check the row
  for (int j = 0; j < 9; j++)
  {
    if (board[r][j] == n)
      return false;
  }
  // Check the column
  for (int i = 0; i < 9; i++)
  {
    if (board[i][c] == n)
      return false;
  }
  // Check the 3x3 subgrid
  int r2 = (r / 3) * 3;
  int c2 = (c / 3) * 3;
  for (int i = r2; i < r2 + 3; i++)
  {
    for (int j = c2; j < c2 + 3; j++)
    {
      if (board[i][j] == n)
        return false;
    }
  }
  return true;
}
bool sud(vector<vector<char>> &board, int r, int c)
{
  if (r == 9)
    return true; // If we've filled all rows, return true (solved)
  if (c == 9)
    return sud(board, r + 1, 0); // Move to the next row

  if (board[r][c] == '.')
  {
    for (char i = '1'; i <= '9'; i++)
    {
      if (canWePlace(board, r, c, i))
      {
        board[r][c] = i;
        if (sud(board, r, c + 1))
          return true;
        board[r][c] = '.'; // Backtrack
      }
    }
    return false; // If no valid number, return false
  }
  else
  {
    return sud(board, r, c + 1); // Skip pre-filled cells
  }
}
int main()
{
  vector<vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  if (sud(board, 0, 0))
  {
    for (const auto &row : board)
    {
      for (const auto &ch : row)
      {
        cout << ch << " ";
      }
      cout << endl;
    }
  }
  else
  {
    cout << "No solution exists" << endl;
  }
  return 0;
}
