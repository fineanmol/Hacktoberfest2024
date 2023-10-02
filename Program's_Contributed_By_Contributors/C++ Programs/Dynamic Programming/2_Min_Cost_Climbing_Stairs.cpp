#include <bits/stdc++.h>
using namespace std;

/*
    Recursion
*/
int minCost(vector<int> &stairs, int i) {
    if(i < 0) {
        return 0;
    }

    if(i <= 1) {
        return stairs[i];
    }
    
    int ans = min(minCost(stairs, i-1) , minCost(stairs, i-2));
    return stairs[i] + ans;
}

/*
    Recursion + Memoization
*/
int minCost(vector<int> &stairs, int i, vector<int> &dp) {
    if(i < 0) {
        return 0;
    }

    if(i <= 1) {
        return stairs[i];
    }
    
    // int one, two;

    // if(dp[i-1] != 0) one = dp[i-1];
    // else one = minCost(stairs, i-1, dp);
    
    // if(dp[i-2] != 0) two = dp[i-2];
    // else two = minCost(stairs, i-2, dp);


    // dp[i] = stairs[i] + min(one,two);

    if(dp[i] != 0) return dp[i];

    dp[i] = stairs[i] + min(minCost(stairs, i-1, dp), minCost(stairs, i-2, dp));

    return dp[i];
}

/*
    Tabulation
*/
int minCost(vector<int> &stairs) {
    int n = stairs.size();
    vector<int> dp(n, 0);
    dp[0] = stairs[0];
    dp[1] = stairs[1];

    for(int i=2; i<n; i++) {
        int prevCost = min(dp[i-1], dp[i-2]);
        dp[i] = stairs[i] + prevCost;
    }
    
    return min(dp[n-1], dp[n-2]);
}

/*
    Space optimisation
*/
int minCost2(vector<int> &stairs) {
    int n = stairs.size();
    int prev0 = stairs[0];
    int prev1 = stairs[1];

    for(int i=2; i<n; i++) {
        int curr = stairs[i] + min(prev0, prev1);

        prev0 = prev1;
        prev1 = curr;
    }
    
    return min(prev0, prev1);
}

int main() {
    int n;
    cout << "Enter the count of stairs : ";
    cin >> n;

    vector<int> stairs(n,0);
    cout << "Enter the cost of stairs : ";
    for(int i=0; i<n; i++) cin >> stairs[i];

    // int ans = min(minCost(stairs, n-1) , minCost(stairs, n-2));


    // vector<int> dp(n,0);
    // dp[0] = stairs[0];
    // dp[1] = stairs[1];
    // int ans = min(minCost(stairs, n-1, dp), minCost(stairs, n-2, dp));
    
    int ans = minCost2(stairs);
    cout << "Minimum cost: " << ans << endl;

    return 0;
}