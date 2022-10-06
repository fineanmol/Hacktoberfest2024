// Rearrange an array with alternate high and low elements
// Given an integer array, rearrange it such that every second element becomes greater than its left and right
// elements. Assume no duplicate elements are present in the array.
// For example,
// Input: {1, 2, 3, 4, 5, 6, 7}
// Output: {1, 3, 2, 5, 4, 7, 6}
// Input: {9, 6, 8, 3, 7}
// Output: {6, 9, 3, 8, 7}
// Input: {6, 9, 2, 5, 1, 4}
// Output: {6, 9, 2, 5, 1, 4}



#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;

        arr.push_back(value);
    }

    for(int j=1;j<n;j+=2)
    {
                if(arr[j]<arr[j-1])
        {
            swap(arr[j],arr[j-1]);
        }

        if(arr[j]<arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }

    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }

    return 0;
}
