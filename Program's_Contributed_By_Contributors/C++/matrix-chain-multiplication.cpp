#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dp[101][101];
    int solve(int arr[], int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = solve(arr, i, k) + solve(arr, k + 1, j) +
                       arr[i - 1] * arr[k] * arr[j];
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int n, int arr[]) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(arr, 1, n - 1);
    }
};

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    cout << obj.matrixMultiplication(n, arr) << endl;
    return 0;
}