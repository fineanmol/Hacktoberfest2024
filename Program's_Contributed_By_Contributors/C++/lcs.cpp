#include <bits/stdc++.h>
  
int max(int a, int b);
  
int lcs(char* X, char* Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return maxi(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}
  

int maxi(int a, int b)
{
    return (a > b) ? a : b;
}
  

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
  
    int m = strlen(X);
    int n = strlen(Y);
  
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
  
    return 0;
}
