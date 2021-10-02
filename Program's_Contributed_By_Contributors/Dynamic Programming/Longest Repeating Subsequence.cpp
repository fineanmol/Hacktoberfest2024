#include <bits/stdc++.h>

using namespace std;

int solve(string &s1, string &s2, int n1, int n2, vector<vector<int>> &t)
{
    if(n1 == 0 || n2 == 0)
        return 0;

    if(t[n1][n2] != -1)
        return t[n1][n2];

    if((s1[n1-1] == s2[n2-1]) &&  (n1 != n2))
        return t[n1][n2] = 1 + solve(s1,s2, n1-1, n2-1, t);

    else
        return t[n1][n2] = max(solve(s1,s2,n1-1,n2, t), solve(s1,s2,n1,n2-1, t));
}

int LongestRepeatingSubsequence(string str)
{
     string s1, s2;
     s1 =  str;

     s2 = str;

     int n = str.size();

     vector<vector<int>> t(n+1, vector<int>(n+1, -1));

     return solve(s1, s2, n, n, t);
}

int main()
{
     string s;
     
     cout<<LongestRepeatingSubsequence(s)<<endl;
}
