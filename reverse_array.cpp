#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j=n-1;
    int i=0;
    while(i<j){
    swap(arr[i],arr[j]);
    i++;
    j--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
}