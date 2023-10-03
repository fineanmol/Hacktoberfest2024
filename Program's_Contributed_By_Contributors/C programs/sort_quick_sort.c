#include <stdio.h>
#include <conio.h>
void quick_sort(int a[], int lb, int ub);
int partition(int a[], int lb, int ub);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        quick_sort(a, lb, loc - 1);
        quick_sort(a, loc + 1, ub);
    }
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot && start < ub)
        {
            start++;
        }
        while (a[end] > pivot && end > lb)
        {
            end--;
        }
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}

int main()
{
    int n, i;
    printf("Enter size : ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}