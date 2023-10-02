#include <bits/stdc++.h>
using namespace std;

int totalWaysRec(int n) {
    if(n<=0) return 0;
    if(n<=2) return n;
    return totalWaysRec(n-1) + totalWaysRec(n-2);
}

int totalWaysRec2(int n, int i) {
    if(i==n) return 1;
    if(i>n) return 0;
    return totalWaysRec2(n, i+1) + totalWaysRec2(n, i+2);
}

/*
    Recursion + Memoization
*/
int totalWaysDP(int n, vector<int> &dp) {
    if(n<=0) return 0;
    if(n<=2) return n;
    
    if(dp[n] != 0) return dp[n];

    dp[n] = totalWaysDP(n-1, dp) + totalWaysDP(n-2, dp);
    return dp[n];
}

/*
    Tabulation
*/
int totalWaysDP(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

/*
    Space optimisation
*/
int totalWaysDP2(int n) {
    int prev1 = 1;
    int prev2 = 1;

    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    // int n;
    // cout << "Enter n : ";
    // cin >> n;

    // int ans = totalWaysRec(n);

    // vector<int> dp(n+1, 0);
    // int ans = totalWaysDP(n, dp);

    // cout << "Total ways to climb " << n << " stairs : " << ans << endl;

    vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 25, 30, 35, 37};
    for(int i=0; i<input.size(); i++) {
        vector<int> dp(input[i]+1, 0);

        cout << "For " << input[i] << " : ";
        cout << totalWaysRec(input[i]) << " ";
        cout << totalWaysRec2(input[i], 0) << " ";
        cout << totalWaysDP(input[i], dp) << " ";
        cout << totalWaysDP(input[i]) << " ";
        cout << totalWaysDP2(input[i]) << endl;
    }

    return 0;
}