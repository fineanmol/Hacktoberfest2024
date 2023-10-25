class Solution {
  public:

    int f(int i, int j, string & s, string & t, vector < vector < int >> & dp) {
      if (j == t.size()) return 1;
      if (i == s.size()) return 0;
      if (dp[i][j] != -1) return dp[i][j];
      int ans = 0;
      for (int k = i; k < s.size(); k++) {
        if (s[k] == t[j])
          ans += f(k + 1, j + 1, s, t, dp);
      }

      return dp[i][j] = ans;
    }

  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    // Resursion + Memoization method :
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    //  return f(0,0,s,t,dp);


    // DP (Tabulation) method : 
    vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
       if(t[i-1]==s[j-1]){
           dp[i][j]=(dp[i-1][j-1]+dp[i][j-1]) % INT_MAX;
       }
       else
       dp[i][j]=dp[i][j-1];
    }
    }
    return dp[m][n];

  }
};