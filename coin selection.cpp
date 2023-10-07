// Recursive C++ program for 
// coin change problem. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the count of ways we can 
// sum coins[0...n-1] coins to get sum "sum" 
int count(int coins[], int n, int sum) 
{ 

	// If sum is 0 then there is 1 solution 
	// (do not include any coin) 
	if (sum == 0) 
		return 1; 

	// If sum is less than 0 then no 
	// solution exists 
	if (sum < 0) 
		return 0; 

	// If there are no coins and sum 
	// is greater than 0, then no 
	// solution exist 
	if (n <= 0) 
		return 0; 

	// count is sum of solutions (i) 
	// including coins[n-1] (ii) excluding coins[n-1] 
	return count(coins, n, sum - coins[n - 1]) 
		+ count(coins, n - 1, sum); 
} 

// Driver code 
int main() 
{ 
	int i, j; 
	int coins[] = { 1, 2, 3 }; 
	int n = sizeof(coins) / sizeof(coins[0]); 
	int sum = 5; 

	cout << " " << count(coins, n, sum); 

	return 0; 
} 
