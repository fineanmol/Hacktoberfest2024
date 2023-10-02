// DUTCH NATIONAL FLAG ALGO TO SORT ARRAY OF 0,1,2 IN SINGLE PASS

// This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  
// The rules are the following:

// 1. arr[0….low-1] contains 0. [Extreme left part]
// 2. arr[low….mid-1] contains 1.
// 3. arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; 

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// TC - O(N)
// SC - O(1)