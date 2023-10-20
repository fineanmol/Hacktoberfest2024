/*Codes(functions) for Sorting Algorithms*/


#include <iostream>
using namespace std;

void bubbleSort(int array[], int n){
    int flag=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i;j++){
            if(array[j]>array[j+1]){
                swap(array[j], array[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            cout<<"Array already sorted"<<endl;
            break;
        }
    }
}

void Insertionsort(int array[], int n){
    for(int i=1; i<n; i++){
        int j=i-1;
        int x= array[i];
         while(j>-1 && array[j]>x){
             array[j+1]=array[j];
             j--;
         }   
         array[j+1]=x;
    }
}

void selectionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int k, j;
        k=j=i;
        while(++j!=n){
        if(a[j]<a[k]){
            k=j;
        }
    }
    swap(a[i], a[k]);
  }
}
 
int partition(int a[], int l, int h){
    int pivot=a[l];
    int i=l;
    int j=h;
    
    do{
        do{
            i++;
        }while(a[i]<=pivot);
        
        do{
            j--;
        }while(a[j]>pivot);
        
        if(i<j){ 
            swap(a[i], a[j]);
        }
        
    }while(i<j);
    swap(a[j], a[l]);
    
    return j;
}

void quickSort(int a[], int l, int h){
    if(l<h){ 
    int k=partition(a, l, h);
    quickSort(a, l, k);
    quickSort(a, k+1, h);
    }
}
 
 void merge(int arr[], int low, int mid, int high){
     int i= low;
     int j=mid+1;
     int k= low;
     int b[100];
     
     while(i<=mid && j<=high){
         if(arr[i]<arr[j]){
             b[k++]=arr[i++];
        }
         
         else{
         b[k++]=arr[j++];
        }
    }
    
    for(; i<=mid; i++){
        b[k++]=arr[i];
    }
    
    for(; j<=high; j++){
        b[k++]=arr[j];
    }
    
    for(int u=low; u<=high; u++){       
        arr[u]=b[u];
    }

 }
 
 void iMergeSort(int arr[], int n){
     int p;
     int i, l, h, mid;
     for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
             l=i;
             h= i+p-1;
             mid=(l+h)/2;
             
             merge(arr, l, mid, h);
        }
    }
    
//    if(n-i>p/2) 
// { 
// l = i; 
// h = i+p-1; 
// mid = (l+h)/2; 
// merge(A, l, mid, n-1); 
// } 
     
     if(p/2<n){
         merge(arr, 0, p/2-1, n-1);
    }
 }
 
 void mergeRecurssive(int arr[], int low, int high){
     if(low<high){
         int mid= (low+high)/2;
         mergeRecurssive(arr, low, mid);
         mergeRecurssive(arr, mid+1, high);
         merge(arr, low, mid, high);
         
     }
 }
 
 int maxNum(int arr[], int n){
     int max=arr[0];
     for(int i=1; i<n; i++){
         if(arr[i]>max){
             max=arr[i];
         }
     }
     return max;
 }
 
 void countSort(int arr[], int n){
     int max=maxNum(arr, n);
     int *c;
     
     c= new int[max+1];
     for(int i=0; i<=max; i++){
         c[i]=0;
    }
    
    for(int i=0; i<n; i++){
        c[arr[i]]++;
    }
    
    int i=0, j=0;
    while(i<max+1){
        if(c[i]!=0){
            arr[j++]=i;
            c[i]--;
        }
        else{
            i++;
        }
    }
    
    
 }
void printArray(int array[],int n){
    for(int i=0; i<n; i++){
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

int main() {
    cout<< "My template"<<endl;
    int array[]={23,3,19,8,14,12,12,12,12, 24, 68, 32, 9856, 0, 69};
    int size= sizeof(array)/sizeof(array[0]);
    
    cout<<"Bubble Sort"<<endl;
    bubbleSort(array, size);
    printArray(array, size);
    
    cout<<"Insertion Sort"<<endl;
    Insertionsort(array, size);
    printArray(array, size);

    cout<<"Selection Sort"<<endl;
    selectionSort(array, size);
    printArray(array, size);

    cout<<"Quick Sort"<<endl;
    quickSort(array, 0, size-1);
    printArray(array, size);  

    cout<<"Iterative Merge Sort"<<endl;
    iMergeSort(array, size);
    printArray(array, size);

    cout<<"Merge Recursive"<<endl;
    mergeRecurssive(array, 0, size-1);
    printArray(array, size);

cout<<"count sort"<<endl;
countSort(array, size);   
printArray(array, size); 

 return 0;
}
