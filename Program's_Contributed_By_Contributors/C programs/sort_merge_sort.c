#include <stdio.h>
#include <conio.h>

void merge(int a[], int b[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}
void mergesort(int a[], int b[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(a, b, lb, mid);
        mergesort(a, b, mid + 1, ub);
        merge(a, b, lb, mid, ub);
    }
}
int main()
{
    int n, i;
    printf("Enter size : ");
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, b, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}
