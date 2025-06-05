#include<iostream>
using namespace std;

int recursive_sum(int a[],int size);
void printArr(int a[],int size);

int main(){
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    recursive_sum(a,n);
    printArr(a,n);
    return 0;
}

int recursive_sum(int a[], int size){
    int sum;
    if(size==1){
        return a[size-1];
    }
    else{
        sum = a[size-1] + recursive_sum(a,size-1);
        a[size-1] = sum;
    }
}

void printArr(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}