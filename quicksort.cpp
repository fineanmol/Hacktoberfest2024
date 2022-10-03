#include<iostream>
#include<cmath>
using namespace std;
int cnt;
int iPartition(int a[], int left, int right)
{
    int i, j, pivot, temp;
    pivot = a[left];
    i = left + 1;
    j = right;
    while (1)
    {
        while (pivot >= a[i] && i <= right)
        {
            i++;
            cnt++;
        }
        while (pivot < a[j] && j > left)
        {
            j--;
            cnt++;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            a[left] = a[j];
            a[j] = pivot;
            return j;
        }
    }
}
void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = iPartition(arr, l, h);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, h);
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
    qSort(a, 0, n - 1);
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "No of count is " << cnt << endl;
    printf("SIZE\tASC\ttime\tDESC\ttime\tRAND\ttime\n");
    for (int i = 8; i < 1000; i = i * 2)
    {        int   ln=2*i*log(i)/log(2);
        for (int j = 0; j < i; j++)
        {
            a[j] = j;
            b[j] = i - j;
            c[j] = rand() % i;
        }
        cnt = 0;
        qSort(a, 0, i - 1);
        c1 = cnt;
        cnt = 0;
        qSort(b, 0, i - 1);
        c2 = cnt;
        cnt = 0;
        qSort(c, 0, i - 1);
        c3 = cnt;
        cout << endl;
       printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,c1,i*i,c2,i*i,c3,ln);
    }
    cout << endl;
    return (0);
}
