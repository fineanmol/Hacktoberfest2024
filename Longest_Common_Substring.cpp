//Given two strings, the task is to find the length of the longest common substring
//present in the given strings in the same order.


/*
        Simple Approach
The simple approach checks for every substring of sequence 1 whether it is also a substring in sequence 2.

    Let's say Sequence1 and Sequence2 with length n and m respectively

        -Find all the substrings of sequence 1 in O(n^2)
        -Iterate through sequence 2 and check whether the current substring is a substring of this string in O(m)
        -Maximize the length of all the common substrings.
*/
/*
        Dynamic Programming Appraoch
The longest common substring can be efficiently calculated using the dynamic programming approach.

The idea is to calculate the longest common suffix for all substrings of both sequences
*/

//The program given below has applied the dynamic programming method
/*
        Algorithm:

Create a dp array of size N * M, where N and M denote the length of the sequences.
Iterate over the string str1 and str2 using a nested loop.
The below conditions follows:
If i == 0 or j == 0, dp[i][j] = 0
If str1[i] == str2[j], dp[i][j] = 1 + dp[i – 1][j – 1]
Keep a track of the maximum value obtained so far.
Return the maximum value.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find longest common substring.
int LCSubStr(string X, string Y)
{
	int m = X.length();
	int n = Y.length();

	
	int result = 0;


	int len[2][n];

	
	int currRow = 0;

	
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				len[currRow][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1]) {
				len[currRow][j] = len[1 - currRow][j - 1] + 1;
				result = max(result, len[currRow][j]);
			}
			else {
				len[currRow][j] = 0;
			}
		}

	
		currRow = 1 - currRow;
	}

	return result;
}

int main()
{
	string X = "Institution";
	string Y = "Institute";

	cout << LCSubStr(X, Y);
	return 0;
}
