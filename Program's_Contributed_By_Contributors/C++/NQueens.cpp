#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(vector<string> curr, int curRow, int curCol)
    {

        for (int i = 0; i < curr.size(); i++)
        {
            if (curr[curRow][i] == 'Q')
                return false;
            if (curr[i][curCol] == 'Q')
                return false;
        }

        int i = curRow, j = curCol;
        while (i >= 0 && j >= 0)
        {
            if (curr[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = curRow;
        j = curCol;
        while (i >= 0 && j < curr.size())
        {
            if (curr[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(vector<string> curr, vector<vector<string>> &ans, int curRow)
    {
        if (curRow >= curr.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < curr.size(); i++)
        {
            if (check(curr, curRow, i))
            {
                curr[curRow][i] = 'Q';
                helper(curr, ans, curRow + 1);
                curr[curRow][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;

        string str = "";
        for (int i = 0; i < n; i++)
        {
            str += '.';
        }

        vector<string> temp(n, str);
        helper(temp, ans, 0);
        return ans;
    }
};