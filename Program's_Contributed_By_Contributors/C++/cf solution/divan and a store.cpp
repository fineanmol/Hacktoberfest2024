#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 int n,l,r,k,count=0;
 cin>>n>>l>>r>>k;
 int left=k;
 int arr[n];
 for (int i = 0; i < n; i++)
 {
   cin>>arr[i];
 }
 sort(arr,arr+(n-1));
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>=l && arr[i]<=r and arr[i]<=left){
            left-=arr[i];
            count++;
        }
    }
    cout<<count<<endl;
    
}
return 0;
}