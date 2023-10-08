/*
You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

*/
#include <stdio.h>
#include <limits.h>

int max(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int sum(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
int isFeasible(int a[], int n, int mid, int c)
{
    int student = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > mid)
        {
            student++;
            sum = a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    if (student <= c)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int minimumNumber(int a[], int n, int k)
{
    int min = max(a, n);
    int max = sum(a, n);
    int result = 0;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (isFeasible(a, n, mid, k) == 1)
        {
            result = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return result;
}
int main()
{
    int n, k;
    printf("Enter the number of books--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the number of pages in each books--> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the number of students--> ");
    scanf("%d", &k);
    int ans = minimumNumber(a, n, k);
    printf("\nThe minimum number of pages to be allocate is-->%d\n", ans);
    return 0;
}