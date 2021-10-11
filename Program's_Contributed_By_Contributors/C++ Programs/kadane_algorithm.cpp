//Given an array arr of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
    //avoiding brute force to prevent O(n^2)
       int curr_sum=0,omax=arr[0];
    for (int i = 0;i < n;i++) {
        curr_sum+=arr[i];
        curr_sum = max(curr_sum, arr[i]);
        omax = max(curr_sum, omax);
         if(curr_sum<0)
                    curr_sum=0;
    }
    return omax;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}