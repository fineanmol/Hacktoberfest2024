#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[],int low,int high,int x){
    if(low>high)  return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x) return mid;
    else if(x>arr[mid]) return bsearch(arr,mid+1,high,x);
    else  return bsearch(arr,low,mid-1,x);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the number: ";
    cin>>x;
    int low=0; 
    int high=n-1;
    cout<<bsearch(arr,low,high,x);
}