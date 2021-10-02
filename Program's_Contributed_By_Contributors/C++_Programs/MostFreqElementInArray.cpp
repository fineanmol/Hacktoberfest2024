#include <bits/stdc++.h>
using namespace std;
 
int mostFreq(int arr[], int n)
{
    // Sorting
    sort(arr, arr + n);
 
    // using linear traversal
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
 
    // if most freq = last element
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
 
    return res;
}
 
// driver program
int main()
{
	//array
	int arr[] = { 1, 7, 2, 3, 3, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mostFreq(arr, n);
    return 0;
}