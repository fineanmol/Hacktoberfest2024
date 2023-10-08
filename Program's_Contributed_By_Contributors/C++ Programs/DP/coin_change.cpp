#include <bits/stdc++.h> 
using namespace std;

int count(vector<int> coins, int n, int sum)
{
    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];
    return dp[sum];
}

int main()
{
    int n, sum;
    cin>>n;
    vector<int> coins;
    for(auto &i:coins)
        cin>>i;
    cin>>sum;
    cout << count(coins, n, sum);
    return 0;
}