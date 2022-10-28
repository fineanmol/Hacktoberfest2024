#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key)
{
    // base cases
    //  element not found
    if (s > e)
        return false;
    int mid = (s + e) / 2;
    // element found
    if (arr[mid] == key)
        return true;
    // recursion
    if (arr[mid] < key)
    {
        // search right
        binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        // search left
        binarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[6] = {2, 4, 6, 10, 14, 16};
    int size = 6;
    // int key = 14;
    int key = 18;
    cout << binarySearch(arr, 0, 5, key) << endl;
}
