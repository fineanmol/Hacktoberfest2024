#include <stdio.h>

int range_of_even(int *nums, int length, int *min, int *max);

int main(void)
{

    int nums[] = {3, 5, 3, 3, 182933, -23};
    int length = sizeof(nums) / sizeof(nums[0]);
    int min, max;

    if (range_of_even(nums, length, &min, &max))
    {
        printf("Max: %d\nMin: %d", max, min);
    }
    else
        printf("Non sono presenti numeri pari.");
}

int range_of_even(int *nums, int length, int *min, int *max)
{
    int hasEven = 0;
    *max = 0 - (__INT_MAX__ - 1);
    *min = __INT_MAX__;

    for (int i = 0; i <= length - 1; i++)
    {
        if (nums[i] % 2 == 0)
        {
            hasEven = 1;
            if (nums[i] > *max)
            {
                *max = nums[i];
            }
            if (nums[i] < *min)
            {
                *min = nums[i];
            }
        }
    }
    return hasEven;
}