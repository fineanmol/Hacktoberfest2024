#include <bits/stdc++.h>

using namespace std;

int solve(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp)
{
    if(n1 == 0 || n2 == 0)
        return 0;
    if(dp[n1][n2] != -1)
        return dp[n1][n2];

    if(s1[n1-1] == s2[n2-1])
        return dp[n1][n2] = 1 + solve(s1, s2, n1-1, n2-1, dp);

    else
        return dp[n1][n2] = max(solve(s1, s2, n1-1, n2, dp) , solve(s1, s2, n1, n2-1, dp));

}

int shortestCommonSupersequence(string s1, string s2, int n1, int n2)
{
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    int res = solve(s1, s2, n1, n2, dp); 

    return (n1 + n2 - res);
}


int main()
{
     string s1, s2;
     cin>>s1>>s2;
  
     cout<<shortestCommonSupersequence(s1, s2, s1.size(), s2.size())<<endl;
}
