#include <iostream>
using namespace std;
int binarySearch(int *arr,int start,int end,int x){
    int mid = (start+end)/2;
    if (start > end) {
        return -1;
    }
    if(arr[mid]==x){
        return mid;
    }else if(arr[mid]<x){

        start=mid+1;
        binarySearch(arr,start,end,x);
    }else{
        end=mid-1;
        binarySearch(arr,start,end,x);
    }
}
int main(){
    int arr[10]={1,2,3,4,5,6,8,9,10,12};
    cout<<binarySearch(arr,0,9,10);
    
    return 0;
}