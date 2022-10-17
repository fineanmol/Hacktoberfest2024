// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   private:
   long long int solve(string &str,vector<vector<long long int>> &dp,int i,int j){
       // base case
       int mod = 1e9 + 7;
       if(i == j){
           return 1;
       }
       if(i > j){
           return 0;
       }
       
       if(dp[i][j] != -1){
           return dp[i][j];
       }
       
       if(str[i] == str[j]){
           dp[i][j] = (solve(str,dp,i+1,j) + solve(str,dp,i,j-1) + 1) % mod;
       }
       else{
           // Why we added mod 
           // ((a + b)%b) = a % b { (a % b) + b % b = }(explaination)
           // We use above property when we can have negative answer from mod 
           // see we are subtracting solve(str,dp,i+1,j-1), which can cause -ve value
           // 
           
           dp[i][j] = ((solve(str,dp,i+1,j) + solve(str,dp,i,j-1) - solve(str,dp,i+1,j-1)) % mod + mod) % mod;
       }
       
       return dp[i][j];
   }
   public:
   /*You are required to complete below method */
   long long int  countPS(string str)
   {
      int n = str.size();
      vector<vector<long long int>> dp(n,vector<long long int>(n,-1));
      long long int ans = solve(str,dp,0,n-1);
      
      return ans;
   }
    
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
