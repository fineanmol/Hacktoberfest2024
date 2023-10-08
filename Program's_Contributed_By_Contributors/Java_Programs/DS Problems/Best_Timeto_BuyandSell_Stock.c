/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0

*/
int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
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
int maxProfit(int arr[], int n)
{
    int maxProfit = 0, minSofar = arr[0];
    for (int i = 0; i < n; i++)
    {
        minSofar = min(minSofar, arr[i]);
        int profit = arr[i] - minSofar;
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size--> ");
    scanf("%d", &n);
    int prices[n];
    printf("Enter the prices of the stocks--> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }
    int MaxProfit = maxProfit(prices, n);
    printf("\nThe maximum profit you can achive is-->%d\n", MaxProfit);
    return 0;
}