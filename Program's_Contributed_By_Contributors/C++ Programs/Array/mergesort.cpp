#include<iostream>
using namespace std;
//1st approach

void merge(int *a,int s,int e){
    int mid=(s+e)/2;
    
    int l1=mid-s+1;
    int l2=e-mid;

    int *fe =new int[l1];
    int *se=new int[l2];

    int mainarrayindex=s;
    for(int i=0;i<l1;i++){
        fe[i]=a[mainarrayindex++];
    }

    mainarrayindex = mid+1;
    for(int i=0;i<l2;i++){
        se[i]=a[mainarrayindex++];
    }

//merge 2 sorted array
int i1=0;
int i2=0;
mainarrayindex=s;
    while(i1<l1 && i2<l2){
        if(fe[i1]<se[i2]){
            a[mainarrayindex++]=fe[i1++];
        }
        else{
            a[mainarrayindex++]=se[i2++];
        }
    }

    while(i1<l1){
        a[mainarrayindex++]=fe[i1++];
    }

    while(i2<l2){
        a[mainarrayindex++]=se[i2++];
    }
    delete []fe;
    delete []se;
}
void mergesort(int *a,int s,int e){
    if(s>=e){
        return;
    }

int mid = (s+e)/2;
 //to sort left part of array
    mergesort(a,s,mid);
    //to sort right part of array
    mergesort(a,mid+1,e);

    //merge both part
    merge(a,s,e);

}
int main(){
    int a[6]={4,2,1,8,9,0};
    mergesort(a,0,5);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
}