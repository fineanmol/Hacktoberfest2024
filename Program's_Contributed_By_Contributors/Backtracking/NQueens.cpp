#include <bits/stdc++.h>
using namespace std;

void placeQueens(int i, int n, vector<vector<string>> &ans, vector<string> &v, vector<bool> &row, vector<bool> &col, vector<bool> &ld, vector<bool> &rd)
{
    if (i == n)
    {
        ans.push_back(v);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (row[i] + col[j] + ld[i + j] + rd[j - i + n - 1] == 0)
        {
            v[i][j] = 'Q'; //place Queen
            row[i] = col[j] = ld[i + j] = rd[j - i + n - 1] = true;
            placeQueens(i + 1, n, ans, v, row, col, ld, rd);
            row[i] = col[j] = ld[i + j] = rd[j - i + n - 1] = false;
            v[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    string s;
    vector<string> v;
    vector<vector<string>> ans;
    vector<bool> row(n, false), col(n, false), ld(2 * n, false), rd(2 * n, false);
    for (int i = 0; i < n; i++)
    {
        s = s + '.';
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(s);
    }
    placeQueens(0, n, ans, v, row, col, ld, rd);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<string> > ans;
    ans = solveNQueens(n);
    //Display
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();i++)
        {
            cout<<ans[i][j]<<endl;
        }
    } 
}