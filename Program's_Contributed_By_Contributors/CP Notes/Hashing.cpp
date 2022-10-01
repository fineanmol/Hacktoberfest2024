/*
Hadshing is a technique in which we precompute , but the thing that we precompute is actually an array, for eg, we can
precompute the frequency of element of an array and something like that, so as to avoid having antoher loop for each
query, eg quest

Given an array of N integers, given Q queries and in each query given a 
number X, print count of the number in array.

Constraints:
1 <= N <= 10^5
1 <= a[i] <= 10^7
1 <= Q <= 10^5

Now note , if we have two loops in this , one for input and then for finding frequency of each element as its queried
we'll be left with a time complexity of O(n^2), ie 10^10, hence cant be executed in a sec (10^7 max), so we createa a 
hash array and store all the precomputed frequencies while initialization.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10e7; //The max size an array can have
int hsh[N];         //⚠️Global arrays are predefined with 0

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hsh[arr[i]]++;
    }

    while (n--)
    {
        int q;
        cin >> q;
        cout << hsh[q] << endl;
    }
}
