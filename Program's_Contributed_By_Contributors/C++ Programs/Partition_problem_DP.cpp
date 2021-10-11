#include <bits/stdc++.h>
using namespace std;

 
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int s=0;
        for(int i=0;i<N;i++)
        s+=arr[i];
        if(s%2!=0)return 0;
        s/=2;
        int dp[N+1][s+1];
        for(int i=0;i<=N;i++)
        dp[i][0]=1;
        for(int j=1;j<=s;j++)
        dp[0][j]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=s;j++)
            {
                
                if(j>=arr[i-1])
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][s];
    }
};


int main(){
 
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    
    return 0;
}  