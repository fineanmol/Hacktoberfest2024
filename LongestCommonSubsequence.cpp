// Longest Common Subsequence

#include<bits/stdc++.h>

using namespace std;


//recursion approach
int solve(string s1, int i, string s2, int j)
{
    if(i==s1.length() || j==s2.length())return 0;
    if(s1[i]==s2[j])
    {
        return 1 + solve(s1, i+1, s2, j+1);
    }
    else
    {
        return max(solve(s1, i+1, s2, j), solve(s1, i, s2, j+1));
    }
}


//dp approach
int solve2(string s1, string s2)
{
    int dp[s2.length()+1][s1.length()+1];
    for(int i=0; i<=s2.length(); i++)
    {
        for(int j=0; j<=s1.length(); j++)
        {
            if(i==0 || j==0)dp[i][j]=0;
            else if(s2[i-1]==s1[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[s2.length()][s1.length()];
}


int main()
{
    string s1, s2;
    cin>>s1>>s2;
    // cout<<solve(s1, 0, s2, 0)<<endl;
    cout<<solve2(s1, s2)<<endl;
    return 0;

}
