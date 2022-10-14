//i intend to live life not just exist
//Aeron

#include <bits/stdc++.h>
using namespace std;

int iPartition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void qSort(int a[], int l, int h)
{
    if (l < h)
    {
        int p = iPartition(a, l, h);
        qSort(a, l, p - 1);
        qSort(a, p + 1, h);
    }
}

int main()
{

    int a[] = {3,34,23,123,123,1232,546,34234,123,13123,3};

    int n = sizeof(a) / sizeof(a[0]);

    qSort(a, 0, n - 1);

    for (int x : a)
        cout << x << " ";
}