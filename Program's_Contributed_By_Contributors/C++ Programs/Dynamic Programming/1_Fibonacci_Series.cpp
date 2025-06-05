#include <bits/stdc++.h>
using namespace std;

int fibRec(int n) {
    if(n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

/*
    Top-down approach (Recursion + Memoisation)
    TC : O(N)
    SC : O(N) + O(N) : O(N)
*/
int fibDP(int n, vector<int> &dp) {
    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fibDP(n-1, dp) + fibDP(n-2, dp);
    return dp[n];
}

/*
    Bottom-up approach (Tabulation)
    TC : O(N)
    SC : O(N)
*/
int fibDP(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

/*
    Space optimisation approach
    TC : O(N)
    SC : O(1)
*/
int fibDP2(int n) {
    if(n <= 1) return n;

    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2;
        
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    // int ans = fibRec(n);
    
    vector<int> dp(n+1, -1);
    int ans = fibDP(n, dp);
    
    cout << "Nth fibonacci number : " << ans << endl;

    return 0;
}