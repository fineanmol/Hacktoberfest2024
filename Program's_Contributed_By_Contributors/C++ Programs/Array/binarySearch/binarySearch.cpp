#include <bits/stdc++.h>
using namespace std;
// this generate function generates a random array of given size and range
void generate(vector<int> &a, int size, int range)
{
    for (int i = 0; i < size; i++)
    {
        a.push_back(rand() % range);
    }
}

// actual binary search program 
int binary_search(vector<int> &t, int x)
{
    int p = 0;
    int r = t.size();
    int mid;
    int low = p;
    int high = max(p, r + 1), count = 0;
    while ((low < high))
    {
        mid = (low + high) / 2;
        if ((x <= t[mid]))
        {
            ++count;
            high = mid;
        }
        else
        {
            ++count;
            low = mid + 1;
        }
    }
    cout << "c1: " << count << endl;
    cout << "c2: " << log(r) << endl;
    cout << "Const. of proportionality: " << count / (log(r)) << endl; // shows the ratio between: (actual number of comparisions) / (expected number of comparisions)
    if (t[high] == x)
        return high;
    return -1;
}

int main()
{
    vector<int> array;
    int size, range, search;
    cout << "Enter the size of array: " << endl;
    cin >> size;
    cout << "Enter the range of random numebrs: " << endl;
    cin >> range;
    generate(array, size, range);
    sort(array.begin(), array.end());
    cout << "Sorted array: " << endl;
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";

    cout << "\nEnter the element to binary search: " << endl;
    cin >> search;
    int found = binary_search(array, search);
    if (found > -1)
    {
        cout << "Element FOUND at index: " << found << endl;
    }
    else
    {
        cout << "Element NOT FOUND" << endl;
    }
    return 0;
}
