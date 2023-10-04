#include <bits/stdc++.h>
using namespace std;
int linsearch(int arr[],int n,int item){
    cout <<"The array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        if(arr[i]==item){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,item;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>item;
    int index=linsearch(arr,n,item);
    if(index==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<index;
    }

    return 0;
}