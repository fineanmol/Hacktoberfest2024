// Online C compiler to run C program online
#include <stdio.h>
void helpers(int arr[], int llen, int rlen, int arrIndex[], int arrIndex1[], int arrIndex2[], int arr1[], int arr2[], int start)
{
    int p1 = 0;
    int p2 = 0;
    int i = start;
    while (p1 < llen && p2 < rlen)
    {
        if (arr1[p1] <= arr2[p2])
        {
            arr[i] = arr1[p1];
            arrIndex[i] = arrIndex1[p1];
            p1 += 1;
        }
        else
        {
            arr[i] = arr2[p2];
            arrIndex[i] = arrIndex2[p2];
            p2 += 1;
        }
        i += 1;
    }
    while (p1 < llen)
    {
        arr[i] = arr1[p1];
        arrIndex[i] = arrIndex1[p1];
        p1 += 1;
        i += 1;
    }
    while (p2 < rlen)
    {
        arr[i] = arr2[p2];
        arrIndex[i] = arrIndex2[p2];
        p2 += 1;
        i += 1;
    }
}
void mergeer(int arr[], int arrIndex[], int start, int mid, int end)
{
    int arr1[mid - start + 1];
    int arr2[end - mid];
    int arrIndex1[mid - start + 1];
    int arrIndex2[end - mid];
    for (int i = 0; i < mid - start + 1; i++)
    {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < mid - start + 1; i++)
    {
        arrIndex1[i] = arrIndex[start + i];
    }
    for (int i = 0; i < end - mid; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }
    for (int i = 0; i < end - mid; i++)
    {
        arrIndex2[i] = arrIndex[mid + 1 + i];
    }
    int llen = mid - start + 1;
    int rlen = end - mid;
    helpers(arr, llen, rlen, arrIndex, arrIndex1, arrIndex2, arr1, arr2, start);
}
void mergeeSort(int arr[], int arrIndex[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    else
    {

        int mid = (start + end) / 2;
        mergeeSort(arr, arrIndex, start, mid);
        mergeeSort(arr, arrIndex, mid + 1, end);
        mergeer(arr, arrIndex, start, mid, end);
    }
}
void printFunc(int arr1[], int arr2[], int n, int k)
{
    int i = 0;
    int j = 1;
    while (i < n || j < n)
    {
        if (arr1[i] != j)
        {
            if (i == 0)
            {
                printf("%d", -1);
                printf("\n");
            }
            else
            {
                printf("%d", -1);
                printf("\n");
            }

            j++;
        }
        else
        {
            if (arr1[i] == arr1[i + 1])
            {
                while (arr1[i] == arr1[i + 1])
                {
                    printf("%d ", arr2[i]);
                    i += 1;
                }
                printf("%d", arr2[i]);
                printf("\n");
                i += 1;
                j += 1;
            }
            else
            {
                if (i == 0)
                {
                    printf("%d", arr2[i]);
                    printf("\n");
                }
                else
                {
                    printf("%d", arr2[i]);
                    printf("\n");
                }

                i += 1;
                j += 1;
            }
        }
    }
    printf("%d", i);
    printf("%d", arr1[i - 1]);
    while (arr1[i - 1] < k)
    {
        printf("%d\n", -1);
        arr1[i - 1]++;
    }
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[k];
    int following[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &arr[i], &following[i]);
    }
    mergeeSort(arr, following, 0, k - 1);
    // for(int i=0;i<n;i++)
    printFunc(arr, following, k, n);

    return 0;
}