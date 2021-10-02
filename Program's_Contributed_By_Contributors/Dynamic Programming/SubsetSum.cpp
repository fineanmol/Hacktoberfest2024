#include<bits/stdc++.h>
using namespace std;


bool solve(int arr[], int n, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return 1;
        if(n == 0)
            return 0;
        if(dp[n][sum] != -1)
            return dp[n][sum];
        if(arr[n-1] <= sum)
            return dp[n][sum] = solve(arr, n-1, sum-arr[n-1], dp) || solve(arr, n-1, sum, dp);
        else
            return dp[n][sum] = solve(arr, n-1, sum, dp);
    }

bool isSubsetSum(int n, int arr[], int sum)
    {
         vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

         return solve(arr, n, sum, dp);
    }




int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int N = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;
    if(isSubsetSum(N, arr, sum) == true)
	cout<<"The given Sum exist"<<endl;
    else
	cout<<"The Given Sum Does not Exist"<<endl;
    return 0;

}
