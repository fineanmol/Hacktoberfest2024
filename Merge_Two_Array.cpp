#include <iostream>
using namespace std;

void merge(int a[], int b[], int c[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < n)
    {
        c[k] = a[j];
        k++;
        j++;
    }
}

int main()
{
    int n, m, q, i, a[10], b[10], c[20];
    cout << "elm : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "elm2 : ";
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    merge(a, b, c, m, n);
    for (int i = 0; i < n + m; i++)
    {
        cout << c[i] << " ";
    }
}
