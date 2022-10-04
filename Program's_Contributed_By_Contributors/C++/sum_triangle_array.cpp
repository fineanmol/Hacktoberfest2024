
/*
 SUM TRIANGLE ARRAY
arr = 1,2,3,4,5
   output:
          48
          20,28
          8,12,16
          3,5,7,9
          1,2,3,4,5
*/
#include <bits/stdc++.h>
using namespace std;


void sumTriangle(int a[],int n)
{
    if(n<1) return;
    //creating an array that stores added elements
    int temp[n];
    
    //adding numbers in an array 
    for(int i=0; i<n-1; i++)
    {
        int x = a[i]+a[i+1];
        temp[i] = x;
    }
    
    //calling function
    sumTriangle(temp,n-1);
    
    
    //printing numbers
    
    for(int i=0; i<n; i++)
    {
        if(i == n-1){
        cout<<a[i]<<endl;
        }
         else{
         
        cout<<a[i]<<",";
    }
    }
    
    
    
}
int main()
{
    int arr[5]={1,2,3,4,5};
    sumTriangle(arr,5);

    return 0;
}