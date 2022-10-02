#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
       {
            // Your code here
            int *merged=new int[r-l+1];
            int indx1=l;
            int indx2=m+1;
            int k=0;
            while(indx1<=m and indx2<=r){
                if(arr[indx1]<arr[indx2]){
                    merged[k++]=arr[indx1++];
                }
                else{
                    merged[k++]=arr[indx2++];
                }
            }
            while(indx1<=m){
                merged[k++]=arr[indx1++];
            }
            while(indx2<=r){
                merged[k++]=arr[indx2++];
            }
            for(int i=0,j=l;i<r-l+1;i++,j++){
               arr[j]= merged[i];
            }
            delete(merged);
       }
       public:
       void mergeSort(int arr[], int l, int r)
       {
           //code here
           if(l>=r){
               return;
           }
           int mid=(l+r)/2;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,r);
           merge(arr,l,mid,r);
       }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
