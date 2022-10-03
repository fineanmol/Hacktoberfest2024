#include <bits/stdc++.h>
using namespace std;
int cnt;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {

        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {

        largest = r;
    }
    cnt++;
    if (largest != i)
    {

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {

        heapify(arr, n, i);
    }
}
void heapSort(int arr[], int n)
{
    buildheap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        cnt++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(a, n);
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "No of count is " << cnt << endl;
    cout << "SIZE"<< " " << "ASC"<< " " << "DESC" << " " << "RAND" << endl;
    for (int i = 8; i < 1000; i = i * 2)
    {
        int ln = 2 * i * log(i) / log(2);
        for (int j = 0; j < i; j++)
        {
            a[j] = j;
            b[j] = i - j;
            c[j] = rand() % i;
        }
        cnt = 0;
        heapSort(a, i);
        c1 = cnt;
        cnt = 0;
        heapSort(b, i);
        c2 = cnt;
        cnt = 0;
        heapSort(c, i);
        c3 = cnt;
        cout << endl;
        cout << i << "  " << c1 << "  " << ln << " " << c2 << " " << ln << "  " << c3 << " " << ln << endl;
    }
    cout << endl;

    return (0);
}
