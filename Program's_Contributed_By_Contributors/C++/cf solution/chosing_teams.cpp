#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
 int n,k,count=0;
 cin>>n>>k;
 int arr[n];
 
 for (int i = 0; i <n; i++)
 {
    cin>>arr[i];
    if((5-arr[i])>=k){
        count++;
    }
 }
 
 int ans=count/3;
 if(ans>=1){
    cout<<ans<<endl;
 }
 else{
    cout<<0<<endl;
 }

 
return 0;
}