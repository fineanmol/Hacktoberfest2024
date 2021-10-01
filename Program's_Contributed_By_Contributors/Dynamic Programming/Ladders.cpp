// Solution of problem Ladders - E-Olymp (https://www.e-olymp.com/en/problems/989)

#include <cstdio>
using namespace std;

int n, dp[100];

int main()
{
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i + j <= n)
                dp[j + i] += dp[j];
        }
    }
    printf("%d\n", dp[n]);
}