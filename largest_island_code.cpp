#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> grid, vector<vector<bool>> visited, int i, int j, int m, int n)
{
    visited[i][j] = true;
    int cs = 1;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && !visited[nx][ny])
        {
            int subC = dfs(grid, visited, nx, ny, m, n);
            cs += subC;
        }
    }
    return cs;
}

int getLargestArea(vector<vector<int>> grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int largest = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                int size = dfs(grid, visited, i, j, m, n);

                if (size > largest)
                    cout << size << endl;
                largest = size;
            }
        }
    }
    return largest;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    cout << getLargestArea(grid) << endl;

    return 0;
}