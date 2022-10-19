#include<iostream>
using namespace std;

void merge(int *arr1, int si, int ei){
   int size= ei-si+1;
   int mid=(si+ei)/2;
   int *arr2=new int[size];

   int i=si;
   int j=mid+1;
   int k=0;


    

    while(i<=mid && j<=ei){

    if (arr1[i]<arr1[j])
    {
        arr2[k++]=arr1[i++];
        
    }

    else{
        arr2[k++]=arr1[j++];
        
    }}

    while (i<=mid)
    {
        arr2[k++]=arr1[i++];
        
    }
    
    while (j<=ei)
    {
        arr2[k++]=arr1[j++];
        
    }

    int f=0;


    for (int x = si; x <= ei; x++)
    {
        arr1[x]=arr2[f++];
        
    }
    
    delete [] arr2;


}

void sort(int *arr1, int si, int ei){

    if (si>=ei)
    {
        return ;
    }
    
    int mid=(si+ei)/2;
    
    sort(arr1, si, mid);
    sort(arr1, mid+1, ei);

    merge(arr1, si, ei);    
}

int main()
{
    int n;
    cin>>n;
    int *arr1=new int[n];
    for (int i = 0; i < n; i++)
    {
      cin>>arr1[i];  
    }
    

    sort(arr1, 0, n-1);

    for (int i = 0; i < n; i++)
    {
      cout<<arr1[i]<<" ";  
    }

    delete [] arr1;
}