/*
Name : Rounak Ghosh
Username : Rounak-Ghosh
About : 4th year undergrad student at GCETTB
*/

#include<iostream>
#include<climits>
#include <vector>
using namespace std;

int rainwater(int arr[], int n)
{
    int left[n], left_max=INT_MIN;
    for(int i=0; i<n; i++)
    {
        left_max = max(left_max, arr[i]);
        left[i] = left_max;
        cout << left[i] << " ";
    }
    cout << endl;
    int right[n], right_max=INT_MIN;
    for(int i=n-1; i>=0; i--)
    {
        right_max = max(right_max, arr[i]);
        right[i] = right_max;
        cout << right[i] << " ";
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int h = min(left[i], right[i]) - arr[i];
        ans += h;
    }
    cout << "\n" << ans;
    return 0;
}

int main()
{
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = 12;
    rainwater(arr, n);
    return 0;
}