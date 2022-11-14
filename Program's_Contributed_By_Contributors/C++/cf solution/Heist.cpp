#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
 int n;
 cin>>n;
 int count=0;
 int arr[n];
 for (int i = 0; i < n; i++)
 {
    cin>>arr[i];

 }
 sort(arr,arr+(n));
 int y = arr[n-1];
 int x= arr[0];

 int ans = y-x-n+1;
 
std::cout<<ans<<endl;
 
return 0;
}