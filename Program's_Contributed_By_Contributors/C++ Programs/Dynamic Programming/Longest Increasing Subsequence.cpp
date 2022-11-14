#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> v;
    v.push_back(arr[0]);
    int ans=1;
    for(int i=1;i<n;i++){
        if(arr[i]>v.back())v.push_back(arr[i]),ans++;
        else{
            int it=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            v[it]=arr[i];
        }
    }
    return ans;
}
