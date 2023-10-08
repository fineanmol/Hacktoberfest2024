#include<bit/stdc++.h>
using namespace std;
#define ll long long

class Solution{
  bool check(vector<ll> A,vector<ll> B,int N){
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());

  return (A==B);
  }
};

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<ll> arr(n,0), brr(n,0);

    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    for(ll i=0;i<n;i++){
        cin>> brr[i];
    }
    Solution ob;
    cout<< ob.check(arr,brr,n)<<"\n";
  }
  return 0;

}
