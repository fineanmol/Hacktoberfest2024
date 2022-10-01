/*
Program to find the max subarray sum of a given circular array

Here we have 2 cases, 
One that doesn't require wrapping => going from last to first element, aka we get our max sum without having to return back 
eg. -1,4,-6,7,5,-4
This can easily be found out using kadanes algo.

The second case is where we will require wrapping,
eg 4,-4,6,-6,10,-11,12
=> Yaha ka max sum ke liye we go 12+4-4+6-6+10 ie 22

to, logic is Max Sum = Total Sum - Sum of non-contributing elements (jisko exclude kiya gaya jaise yaha pe 11).
*/

#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n)
{ //Kadanes algorithm: To find out max Subarray sum
    int csum = 0;
    int msum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        csum += arr[i];
        if (csum < 0)
        {
            csum = 0;
        }
        msum = max(csum, msum);
    }
    return msum;
}

int main()
{
    int n, totSum = 0, wrapsum, nwrapsum;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nwrapsum = kadane(arr, n);

    /*Now to find the sum of Non-Contributing elements we first reverse the signs of elements in the array and then use kadane algo
    */
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
        arr[i] = -arr[i];
    }

    //Non Cont. elems ka sum kadane(arr,n)
    wrapsum = totSum + kadane(arr,n); 
    //Baki simple, if wapping is reqd. then nwrap sum is the answer else wrapsum.
    cout<<max(wrapsum,nwrapsum);

    return 0;
}