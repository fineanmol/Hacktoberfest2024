#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l,int mid, int h)
{
    int n_l = mid-l+1, n_r = h-mid;
    int arr_l[n_l], arr_r[n_r];
    
    for(int i=0; i<n_l; i++)
    {
        arr_l[i] = arr[l+i]; 
    }
    
    for(int j=0; j<n_r; j++)
    {
        arr_r[j] = arr[mid+j+1];
    }
    
    int i=0,j=0,k=l;
    
    while(i<n_l && j<n_r)
    {
        if(arr_l[i]<=arr_r[j])
        {
            arr[k]=arr_l[i];
            i++;
        }
        else
        {
            arr[k]=arr_r[j];
            j++;
        }
        k++;
    }
    
    while(i<n_l)
    {
        arr[k]=arr_l[i];
        i++;
        k++;
    }
    while(j<n_r)
    {
        arr[k]=arr_r[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main()
{
    int arr[10] = {34,12,45,2,89,67,64,589,21,54};
    mergesort(arr,0,9);
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
}