#include<bits/stdc++.h>
using namespace std;
 
int unboundedKnapsack(int W, int n,
                       int val[], int wt[])
{
    
    int dp[W+1];
    memset(dp, 0, sizeof dp);
 
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
    return dp[W];
}
 
int main()
{
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
        cin>>val[i];
        
    for(int i=0;i<n;i++)
        cin>>wt[i];
 
    cout << unboundedKnapsack(w, n, val, wt);
 
    return 0;
}