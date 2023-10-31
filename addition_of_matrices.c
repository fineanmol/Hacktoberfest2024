#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d", &m);
    scanf("%d", &n);
    long long int arr[m][n];
    long long int arr1[m][n];
    long long int arr2[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr1[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = arr[i][j] + arr1[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lld ", arr2[i][j]);
        }
        printf("\n");
    }
  return 0;
}
