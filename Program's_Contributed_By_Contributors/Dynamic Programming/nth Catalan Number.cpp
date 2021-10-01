#include <bits/stdc++.h>

using namespace std;


cpp_int solve(int n, vector<cpp_int> &dp)
    {
        if(n == 0 || n == 1)
            return 1;
            
        if(dp[n] != -1)
            return dp[n];
        
        cpp_int ans = 0;
        for(int i=0; i<=(n-1); i++)
        {
            ans += solve(i, dp) * solve(n-1-i, dp);
        }
        
        return dp[n] = ans;
    }
    
cpp_int findCatalan(int n) 
    {
        vector<cpp_int> dp(n+1, -1);
        
        return solve(n, dp);
    }

int main()
{
     cpp_int n;
     cin>>n;
     
     cout<<"The "<<n<<"th Catalan Number is "<<findCatalan(n)<<endl;
}


