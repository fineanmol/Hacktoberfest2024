//Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

//Solution using 2 pointer approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>ar(n);

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }


    int l=0,r=n-1;
    int maxl=ar[0],maxr=ar[n-1],ans=0;;
    while(l<=r)
    {
        if(ar[l]<=ar[l])
        {
             maxl=max(maxl,ar[l]);
            ans+=maxl-ar[l];
            l++;
        }
        else
        {
            maxr=max(maxr,ar[r]);
            ans+=maxr-ar[r];
            r--;
        }
    }

    cout<<ans<<endl;
}