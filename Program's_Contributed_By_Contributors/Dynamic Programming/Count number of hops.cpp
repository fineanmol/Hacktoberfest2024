#include <bits/stdc++.h>

using namespace std;

int m = 1000000007;
long long int solve(int n, vector<long long int> &dp)
{
    if(n == 0 || n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(dp[n] != -1)
        return dp[n];

    return dp[n] = ((solve(n-1, dp)%m) + (solve(n-2, dp)%m) + (solve(n-3, dp)%m))%m;
}
long long countWays(int n)
{
    vector<long long int> dp(n+1, -1);
    return solve(n, dp);

}


int main()
{
     long long int n;
     cin>>n;
     
     cout<<"The number of ways are "<<countWays(n)<<endl;
}
