#include<iostream>
using namespace std;

vector<vector<int>>dp(1003);
int knapsack(vector<int> &A, vector<int> &B, int w, int n,vector<vector<int>>&dp){
    if(n==0||w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(B[n-1]<=w){
        dp[n][w]=max(A[n-1]+knapsack(A,B,w-B[n-1],n-1,dp),knapsack(A,B,w,n-1),dp);
    }
    else{
        dp[n][w]=knapsack(A,B,w,n-1,dp);
    }
    return dp[n][w];
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int i,j;
    for(i=0;i<1003;i++){
        for(j=0;j<1003;j++){
            dp[i].push_back(-1);
        }
    }
    return knapsack(A,B,C,A.size(), dp);
}
