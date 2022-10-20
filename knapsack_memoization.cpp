#include <bits/stdc++.h>
using namespace std;

int static dp[102][1002];

int knapsack(int weight[], int val[], int w, int n){
    if(w==0||n==0){
        return 0;
    }
    if(dp[w][n]!=-1){
        return dp[w][n];
    }
    if(weight[n-1]<=w){
        return dp[w][n] = max((val[n-1] + knapsack(weight, val, w-weight[n-1], n-1)), knapsack(weight, val, w, n-1));
    }else{
        return dp[w][n] = knapsack(weight, val, w, n-1);
    }
}
int main(){
    int n = 3;
    int val[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int w = 50;
    memset(dp, -1, sizeof(dp));
    cout << knapsack(weight, val, w, n);
}
