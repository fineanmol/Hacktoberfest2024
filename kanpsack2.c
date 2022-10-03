#include <stdio.h>
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int knap[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (wt[i - 1] <= w)
                knap[i][w] = max(val[i - 1] + knap[i - 1][w - wt[i - 1]], knap[i - 1][w]);
            else
                knap[i][w] = knap[i - 1][w];
        }
    }
    return knap[n][W];
}
void main()
{
    int value[] = {4, 5, 6, 7};
    int weight[] = {2, 3, 4, 5};
    int W = 6; // 6kg
    printf("0/1 knapsack using dynamic approach \n");
    int n = 4;
    printf("Total profit value is : %d", knapsack(W, weight, value, n));
}
