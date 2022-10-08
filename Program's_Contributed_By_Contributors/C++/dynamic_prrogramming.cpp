#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int x;
    cin >> x;
    vector<vector<int>> dp(n+1, vector<int> (x+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<n+1; i++){
        for(int j=0; j<x+1; j++){
            if(j-a[i-1] >= 0){
                dp[i][j] += dp[i][j-a[i-1]];
            }
            dp[i][j] += dp[i-1][j];
        }
    }

    cout << dp[n][x] << endl;
    return 0;
}
