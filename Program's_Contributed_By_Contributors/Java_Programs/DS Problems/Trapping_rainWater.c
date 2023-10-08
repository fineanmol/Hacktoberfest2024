/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
*/
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

int trap(int *height, int heightSize)
{
    int left[heightSize], right[heightSize];
    left[0] = height[0];
    right[heightSize - 1] = height[heightSize - 1];
    for (int i = 1; i < heightSize; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }
    for (int i = heightSize - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < heightSize; i++)
    {
        ans += (min(left[i], right[i]) - height[i]);
    }
    return ans;
}
int main()
{
    int n;
    printf("Enter the size--> ");
    scanf("%d", &n);
    printf("Enter the height of the building blocks--> ");
    int height[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }
    int ans = trap(height, n);
    printf("\nThe amount of water can be trapped is-->%d\n", ans);
    return 0;
}