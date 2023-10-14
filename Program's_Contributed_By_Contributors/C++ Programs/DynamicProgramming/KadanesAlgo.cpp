#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
    // Your code here
    long ans = LONG_MIN;
    long curr = 0;
    
    for(int i=0; i<n; i++){
        curr += arr[i];
        ans = max(ans, curr);
        if(curr < 0){
            curr = 0;
        }
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxSubarraySum(arr, n)<<endl;
}