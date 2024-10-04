#include <iostream>
#include <vector>
using namespace std;

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
{
  if (i == n - 1 and j == n - 1)
  {
    ans.push_back(move);
    return;
  }
  // down
  if (i + 1 < n and !vis[i + 1][j] and a[i + 1][j] == 1)
  {
    vis[i][j] = 1;
    solve(i + 1, j, a, n, ans, move + 'D', vis);
    vis[i][j] = 0;
  }
  // left
  if (j - 1 >= 0 and !vis[i][j - 1] and a[i][j - 1] == 1)
  {
    vis[i][j] = 1;
    solve(i, j - 1, a, n, ans, move + 'L', vis);
    vis[i][j] = 0;
  }
  // right
  if (j + 1 < n and !vis[i][j + 1] and a[i][j + 1] == 1)
  {
    vis[i][j] = 1;
    solve(i, j + 1, a, n, ans, move + 'R', vis);
    vis[i][j] = 0;
  }
  // upword
  if (i - 1 >= 0 and !vis[i - 1][j] and a[i - 1][j] == 1)
  {
    vis[i][j] = 1;
    solve(i - 1, j, a, n, ans, move + 'U', vis);
    vis[i][j] = 0;
  }
}

int main()
{
  int n = 4;
  vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  vector<string> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0));
  if (m[0][0] == 1)
    solve(0, 0, m, n, ans, "", vis);

  for(auto ele: ans){
    cout<<ele<<" ";
  }
  return 0;
}