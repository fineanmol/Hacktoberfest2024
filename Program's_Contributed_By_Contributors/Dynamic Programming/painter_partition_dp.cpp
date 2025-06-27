// A DP based CPP program for painter's partition problem
#include <climits>
#include <iostream>
using namespace std;


int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

int findMax(int arr[], int n, int k)
{
	int dp[k + 1][n + 1] = { 0 };

	for (int i = 1; i <= n; i++)
		dp[1][i] = sum(arr, 0, i - 1);

	for (int i = 1; i <= k; i++)
		dp[i][1] = arr[0];

	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++) {

			int best = INT_MAX;

			for (int p = 1; p <= j; p++)
				best = min(best, max(dp[i - 1][p],
							sum(arr, p, j - 1)));	

			dp[i][j] = best;
		}
	}

	return dp[k][n];
}

// driver function
int main()
{
	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << findMax(arr, n, k) << endl;
	return 0;
}
