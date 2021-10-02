// Given two strings. The task is to find the length of the longest common substring.


// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.
// Example 2:

// Input: S1 = "ABC", S2 "ACB"
// Output: 1
// Explanation: The longest common substrings
// are "A", "B", "C" all having length 1.

// Code:
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:

    int longestCommonSubstr (string X, string Y, int m, int n)
    {
        // your code here
        int LCSuff[m + 1][n + 1];
        int result = 0; // To store length of the longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = 1+LCSuff[i - 1][j - 1];
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
