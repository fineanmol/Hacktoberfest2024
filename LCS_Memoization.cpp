#include <bits/stdc++.h>
using namespace std;
int static dp[1002][1002];

int lcs(string a, string b, int n, int m){
    if(n==0||m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(a[n-1]==b[m-1]){
        return dp[n][m] = 1+lcs(a, b, n-1, m-1);
    }else{
        return dp[n][m] = max(lcs(a, b, n-1, m), lcs(a, b, n, m-1));
    }
}
int main(){
string a = "frehjbfc";
    string b = "jfdsbzf";
    int n = a.length();
    int m = b.length();
    memset(dp, -1, sizeof(dp));
    cout << lcs(a, b, n, m) << endl;
}
