/* C++ implementation of LIS problem */
#include <bits/stdc++.h>
using namespace std;

/* lis prints the length and the longest
  increasing subsequence in arr[] of size n */
void lis_and_print(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // maximum value in lis
    int length = *max_element(lis, lis + n);

    cout << "Length of LIS is " << length << "\n";

    // Prints Longest increasing subsequence in arr[]

    cout << "LIS is ";

    vector<int> longest_inc_sub;
    for (int i = n - 1; i >= 0; i--)
    {
        if (lis[i] == length)
        {
            longest_inc_sub.push_back(arr[i]);
            length--;
        }
    }

    reverse(longest_inc_sub.begin(), longest_inc_sub.end());

    for (auto elem : longest_inc_sub)
        cout << elem << " ";
    cout << "\n";
}

/* Driver program to test above function */
int main()
{
    int arr[] = {20, 32, 19, 43, 31, 60, 51, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    lis_and_print(arr, n);
    return 0;
}