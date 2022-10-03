#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
            cnt++;
        }
        else
        {
            arr[k++] = right[j++];
            cnt++;
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
        cnt++;
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
        cnt++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n, c1, c2, c3;
    cout << "Enter the no of elements to be sorted" << endl;
    cin >> n;
    int a[1000], b[1000], c[1000];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cnt = 0;
    mergeSort(a, 0, n - 1);
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "No of count is " << cnt << endl;
  printf("SIZE\tASC\ttime\tDESC\ttime\tRAND\ttime\n");
    for (int  i = 8; i < 1000; i = i * 2)
    {     int   ln=2*i*log(i)/log(2);
        for (int j = 0; j < i; j++)
        {
            a[j] = j;
            b[j] = i - j;
            c[j] = rand() % i;
        }
        cnt = 0;
        mergeSort(a, 0, i - 1);
        c1 = cnt;
        cnt = 0;
        mergeSort(b, 0, i - 1);
        c2 = cnt;
        cnt = 0;
        mergeSort(c, 0, i - 1);
        c3 = cnt;
        cout << endl;
       printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,c1,ln,c2,ln,c3,ln);
    }
    cout << endl;
    return (0);
}
