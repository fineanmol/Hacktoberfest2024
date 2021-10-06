#include <bits/stdc++.h>
using namespace std;

int rwt(int a[], int n)
{
    int res = 0;
    int lmax[n], rmax[n];

    lmax[0] = a[0];
    for (int i = 1; i < n - 1; i++)
        lmax[i] = max(a[i], lmax[i - 1]);

    rmax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(a[i], rmax[i + 1]);

    for (int i = 1; i < n - 1; i++)
        res = res + min(lmax[i], rmax[i]) - a[i];

    return res;
}

int main()
{
    int arr[] = {5, 4, 6, 0, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << rwt(arr, n) << endl;

    return 0;
}