#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(vector<pair<int,int>>&value,int w,int n)
{
    if(w==0||n==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
        if(value[n-1].first<=w)
        {

            return (dp[n][w]=max((value[n-1].second)+knapsack(value,w-(value[n-1].first),n-1),knapsack(value,w,n-1)));
        }
        else
        {
            return dp[n][w]=knapsack(value,w,n-1);
        }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cout<<"ENTER THE  NUMBER OF ITEMS: "<<endl;
    cin>>n;
    vector<pair<int,int>>value;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        value.push_back(make_pair(a,b));
    }
    int w;
    cout<<"ENTER THE MAX. CAPACITY OF THE KNAPSACK: ";
    cin>>w;
    cout<<endl;
    cout<<knapsack(value,w,n);

    return 0;
}