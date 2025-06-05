#include <iostream>
using namespace std;
#define MAX 100
void maxheapify(int *a,int,int);
void heapsort(int *a,int);
void printarray(int *a,int);
int main(){
    int n,i,a[MAX];
    cout<<"Enter the number of elements you want: ";
    cin>>n;
    cout<<"The entered elements are: ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    heapsort(a,n);
    printarray(a,n);
}
void heapsort(int *a,int n){
    for(int i=n/2-1;i>=0;i--){ 
        maxheapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){     
        int c=a[0];
        a[0]=a[i];
        a[i]=c;
        maxheapify(a,i-1,0);
    }
}

void maxheapify(int *a,int n,int i){
        int largest=i;
        int left=(2*i)+1;
        int right=(2*i)+2;
        if(left<=n && a[left]>a[largest]){
            largest=left;
        }
        if(right<=n && a[right]>a[largest]){
            largest=right;
        }
        if(largest!=i){
            int c=a[i];
            a[i]=a[largest];
            a[largest]=c;
            maxheapify(a,n,largest);
        }
 }
void printarray(int *a,int n){
   cout<<"The elements in sorted array are: ";
   for(int i=0;i<n;i++){
       cout<<a[i]<<' ';
   }
}
    
