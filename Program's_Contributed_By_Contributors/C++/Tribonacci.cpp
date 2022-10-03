//  Calculate Tribonacci Number i.e  0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81 ...
#include<bits/stdc++.h>
#include<string.h>
using namespace std;


/*
	Tribonacci number using recursion
	Time Complexity : O(2^N)
	Space Complexity : O(N)
*/
int triboRec(int n) {
	if (n <= 1)
		return n;
	if (n == 2)
		return 1;
	return triboRec(n - 1) + triboRec(n - 2) + triboRec(n - 3);
}


/*
	Tribonacci number using memoization
	Time Complexity : O(N)
	Space Complexity : O(N) for recursion stack + O(N) for array space ≡ O(N)
*/
int triboMemo(int n , vector<int> &dp) {
	if ( n <= 1)
		return n;
	if (n == 2)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = triboMemo(n - 1, dp) + triboMemo(n - 2, dp) + triboMemo(n - 3, dp);
}


/*
	Tribonacci number using Tabulation
	Time Complexity : O(N)
	Space Complexity : O(N) only for array space
*/
int triboTab(int n ) {
	vector<int> dp(n, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}

/*
	Tribonacci number using space Optimisation
	Time Complexity : O(N)
	Space Complexity : O(1)
*/
int triboSpc(int n) {
	int prev = 1;
	int prev2 = 1;
	int prev3 = 0;
	int curr = 0;
	for (int i = 3; i <= n; i++)
	{
		curr = prev + prev2 + prev3;
		prev3 = prev2;
		prev2 = prev;
		prev = curr;
	}
	return prev;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << triboRec(n) << endl;
	vector<int> dp(n + 1, -1);
	cout << triboMemo(n, dp) << endl;
	cout << triboTab(n) << endl;
	cout << triboSpc(n);
	return 0;
}