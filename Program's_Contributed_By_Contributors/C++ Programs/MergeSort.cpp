//MERGE-SORT
#include<iostream>
using namespace std;

//merge function take two intervals 
//one from start to mid , second from mid+1 to end 
//and merge them in sorted order

void merge(int arr[], int l, int mid, int r){
    
    int n1 = mid-l+1;
    int n2 = r-mid;

    //temp arrays to store both halves of array
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0, j=0, k=l;

    // traverse both arrays and in each iteration add smaller of both elements in temp 
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }

    //adding all left elements
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int l, int r) {

    if(l<r) {
        int mid = (l+r) / 2;
        //dividing array into two halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){

    int arr[]={3,4,1,5,2};
    mergeSort(arr, 0, 4);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    //1 2 3 4 5

    return 0;
}