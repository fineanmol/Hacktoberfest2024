#include <bits/stdc++.h>
using namespace std;

    int maxSubArray(vector<int>& nums) {

        // nmax is maximum sum
        // nsum is the current sum
        // when hitting positive number, nsum should sum the current number if positive, otherwise update to the current number
        // when hitting negative number, nsum should sum the current number, update nmax if it is smaller
        int nmax = nums[0];
        int nsum = nmax;
        int n = nums.size();

        if ( n == 0 ) return nmax;

        for ( int i = 1; i<n; i++)
        {
            if ( nums[i] >= 0 )
            {
                if ( nsum >= 0 ) nsum += nums[i];
                else
                    nsum = nums[i];

                nmax = max(nmax,nsum);
            }
            else
            {
                nsum += nums[i];
                if ( nmax < nums[i])   nmax = nums[i];
            }
        }
        return nmax;
    }

int main{
    int arr[5];
    vector <int> v;
    for(int i=0;i<5;i++){
        cin>>arr[i];
        v.push_back(arr[i]);
        
    }
    int sum = maxSubArray(v);
    cout<<sum;
    return 0;
}