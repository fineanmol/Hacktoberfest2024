#include<bits/stdc++.h>
using namespace std;
//Function to swap two numbers
void swap (int *xp,int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//Required function
void bubbleSort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubbleSort(a,n);
    cout<<"Array after sorting "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
