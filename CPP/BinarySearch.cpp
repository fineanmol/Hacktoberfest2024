#include <bits/stdc++.h

using namespace std;

int main()
{
    int size, a[10];
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    int start = 0, end = size - 1;
    int mid;
    while (end - start > 1)
    {
        mid = (start + end) / 2;
        if (a[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    if (a[start] == key)
    {
        cout << end;
    }
    else if (a[end] == key)
    {
        cout << key;
    }
    else
    {
        cout << "not present.";
    }
}
