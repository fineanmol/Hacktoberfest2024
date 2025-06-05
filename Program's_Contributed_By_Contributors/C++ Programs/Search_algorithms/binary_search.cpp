
#include <bits/stdc++.h>
using namespace std;

int binsearch( int arr[], int n, int item){
    printf("The array is: ");
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    int beg=0,end=n-1,mid;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==item){
            return mid;
        }
        else if(arr[mid]>item){
            end=mid-1;
        }
        else{
            beg=mid+1;
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
    int index=binsearch(arr,n,item);
    if(index==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<index;
    }

    return 0;
}