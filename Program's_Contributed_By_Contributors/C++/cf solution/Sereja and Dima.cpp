#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
 ll n;
 cin>>n;
 ll arr[n+2];
 ll srej=0,dim=0;
int left=1,right=n,chance=1;
for (int i = 1; i < n+1; i++)
{
    cin>>arr[i];
}
 while(right>=left){
    if(chance%2==1){

    if(arr[left]>=arr[right]){
        srej+=arr[left++];
        
    }
    else{
        srej+=arr[right--];
        
    }
    chance++;
    }
    else if(chance%2==0){

    if(arr[left]>=arr[right]){
        dim+=arr[left++];
        
    }
    else{
        dim+=arr[right--];
        
    }
    chance++;
    }


 }
cout<<srej<<" "<<dim<<endl;

return 0;
}