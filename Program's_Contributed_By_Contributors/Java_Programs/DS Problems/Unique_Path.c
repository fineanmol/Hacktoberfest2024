/*Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.*/

#include <stdio.h>

// using recursion
int count(int a, int b)
{
    if (a == 1 || b == 1)
    {
        return 1;
    }
    else
    {
        /*it breaks the matrix into 2 parts such that 1 part contain all rows except last one, and other part contain all coloumns except last one and recursively calculate results for those parts and combine them
         */
        return count(a, b - 1) + count(a - 1, b);
    }
}
// using dp
int count1(int m, int n)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }
    else
    {
        int dp[m][n];

        for (int i = 1; i < m; i++)
            dp[i][0] = 1;

        for (int j = 1; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}
int main()
{
    int m, n;
    printf("Enter the row and coloumn for the matrix--> ");
    scanf("%d %d", &m, &n);
    int c = count1(m, n);
    printf("\nThe number of unique path is-->%d\n", c);
    return 0;
}