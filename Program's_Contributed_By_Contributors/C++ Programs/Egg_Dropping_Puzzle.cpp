#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[210][210];
    int solve(int e,int f)
    {
        if(f==0||f==1)
        return f;
        
        if(e==1)
        return f;
        
        if(dp[e][f]!=-1)
        return dp[e][f];
        
        int mn=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int lo,hi;
            if(dp[e-1][k-1]!=-1)
            lo=dp[e-1][k-1];
            else
            {
                lo=solve(e-1,k-1);
                dp[e-1][k-1]=lo;
            }
            if(dp[e][f-k]!=-1)
            hi=dp[e][f-k];
            else
            {
                hi=solve(e,f-k);
                dp[e][f-k]=hi;
            }
            int tp=max(lo,hi);
            mn=min(mn,tp);
        }
        return dp[e][f]=1+mn;
        
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        for(int i=0;i<=200;i++)
        {
            for(int j=0;j<=200;j++)
            dp[i][j]=-1;
        }
        return solve(n,k);
        
    }
};

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}