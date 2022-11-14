#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertion_sort(int a[], int n)
{
    int i, j, x;

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}


void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void reverse(int a[], int n)
{
    int temp;
    for (int i = 0; i <= n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

int main()
{
    int n;
    srand(time(0));
    clock_t start, end;
    printf("enter the size of the array");
    scanf("%d", &n);
    int a[n];
    printf("the array elements before sort \n");

    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % 60) + 1;
    }

     //display(a,n);
    printf("\nafter sorting \n");
    start = clock();
    insertion_sort(a, n);

    // display(a,n);
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("total time :%fs\n", total);

    start = clock();
    insertion_sort(a, n);

    // display(a,n);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("total time :%fs\n", total);

    reverse(a, n);
    // display(a,n);

    start = clock();
    insertion_sort(a, n);
    //display(a,n);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("total time :%fs\n", total);

    // display(a,n);
}
