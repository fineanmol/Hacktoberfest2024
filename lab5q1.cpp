#include<bits/stdc++.h>
using namespace std;
void Max_heapify(int arr2[],int f,int size){
    int max=f,l=f*2,r=f*2+1,t;
    if(l<=size && arr2[l]>arr2[max]) {max=l;}
    if(r<=size && arr2[r]>arr2[max]) {max=r;}
    if(f!=max){
        t=arr2[f];
        arr2[f]=arr2[max];
        arr2[max]=t;
        Max_heapify(arr2,max,size);
    }
}
void Max_heap (int arr1[],int start,int end){
    for(int i=(end)/2;i>=start;i--){
        Max_heapify(arr1,i,end);
    }
}
 
void level_ordered(int arr[] ,int size){
          int g=true;
          int i=2,k,m=1,ct=0;
          cout<<"Level order traversal of array is : "<<endl;
          while(g){
              cout<<"Level --> "<<ct<<" : ";
              for(k=m;k<i && k<=size;k++){
                cout<<arr[k]<<" ";
              }
              cout<<endl;
              m=k;
              ct++;
              if(i>size) g=false;
              i=i+pow(2,ct);
              
          }
}
void heapsort(int arr[],int k){
    int i,t;
    for(int i=k;i>=2;i--){
        t=arr[1];
        arr[1]=arr[i];
        arr[i]=t;
        Max_heapify(arr,1,i-1);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<n+1;i++){cin>>arr[i];}
    Max_heap(arr,1,n);
    heapsort(arr,n);
    cout<<"Sorted Array using heapsort is : "<<endl;
    for(int i=1;i<n+1;i++){cout<<arr[i]<<" ";}
    cout<<endl;
    int V[n+1];
    for(int i=1;i<n+1;i++){V[i]=arr[n+1-i];}
    level_ordered(V,n);
    return 0;
}
