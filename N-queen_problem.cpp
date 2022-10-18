#include <bits/stdc++.h>
using namespace std;
#define For(j, i, f) for (int j = i; j <= f; j++)
#define lli long long int
#define endl "\n"
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

bool isSafe(int n, vector<vector<int>> chessboard, int row, int col) {
  For(i, 0, n - 1) { //Checking column
    if (chessboard[i][col]) return false;
  }

// We only need to check the part of two diagonals before the current row.
// Because we have only reached till that row.So those parts are only checked.

  // checking one diagonal
  int i = row, j = col;
  while (i >= 0 && j >= 0) {
    if (chessboard[i][j]) return false;
    i--;
    j--;
  }
  // checking other diagonal
  i = row, j = col;
  while (i >= 0 && j < n) {
    if (chessboard[i][j]) return false;
    i--;
    j++;
  }
  return true;
}

bool solveNQueenProblem(int n, vector<vector<int>> &chessboard, int row = 0) {

  if (row >= n) return true;
  For(col, 0, n - 1) {
    if (!isSafe(n, chessboard, row, col)) continue;
    chessboard[row][col] = 1;
    if (solveNQueenProblem(n, chessboard, row + 1)) return true;
    chessboard[row][col] = 0;
  }
  return false;
}

vector<vector<int>> NQueenProblem(int n) {
  vector<vector<int>> chessboard(n, vector<int>(n, 0));
  if (solveNQueenProblem(n, chessboard))
    return chessboard;
  else {
    cout << "Sorry!It is not solved\n";
    return chessboard;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chessboard = NQueenProblem(n);
  for (auto &&row : chessboard) {
    for (auto &&x : row) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}