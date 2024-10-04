//! knights's tour
#include <iostream>
#include <vector>
using namespace std;

bool f(vector<vector<int>> &grid, int i, int j, int n, int cnt)
{
  if (i < 0 or j < 0 or i >= n or j >= n or grid[i][j] >= 0)
  {
    return false;
  }
  if (cnt == n * n - 1)
  {
    grid[i][j] = cnt;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << grid[i][j] << " ";
      }
      cout << "\n";
    }
    return true;
  }

  grid[i][j] = cnt;
  // Possible knight moves
  if (f(grid, i - 1, j - 2, n, cnt + 1)) return true;
  if (f(grid, i - 2, j - 1, n, cnt + 1)) return true;
  if (f(grid, i + 1, j - 2, n, cnt + 1)) return true;
  if (f(grid, i + 2, j - 1, n, cnt + 1)) return true;
  if (f(grid, i + 1, j + 2, n, cnt + 1)) return true;
  if (f(grid, i + 2, j + 1, n, cnt + 1)) return true;
  if (f(grid, i - 1, j + 2, n, cnt + 1)) return true;
  if (f(grid, i - 2, j + 1, n, cnt + 1)) return true;

  // Backtrack if no moves are valid
  grid[i][j] = -1;
  return false; // This was missing
}

int main()
{
  int n = 3;
  vector<vector<int>> grid(n, vector<int>(n, -1));
  f(grid, 0, 0, n, 0);
  return 0;
}
