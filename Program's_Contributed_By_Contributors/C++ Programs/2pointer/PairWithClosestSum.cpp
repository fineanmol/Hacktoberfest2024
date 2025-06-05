// Simple C++ program to find the pair with sum closest to a given no. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Prints the pair with sum closest to x 
void printClosest(int arr[], int n, int x) 
{ 
    int res_l, res_r;  // To store indexes of result pair 
    
      //variable to store current minimum difference 
      int temp = INT_MAX; 
    
      //iterating over array 
      for(int i=0;i<n-1;i++) 
    { 
          for(int j=i+1;j<n;j++) 
        { 
              //if found more closest pair 
              if(abs(arr[i]+arr[j]-x)<temp) 
            { 
                  res_l=i; 
                  res_r=j; 
                  temp=abs(arr[i]+arr[j]-x); 
            } 
        } 
    } 
  
    cout <<" The closest pair is " << arr[res_l] << " and " << arr[res_r]; 
} 


int main() 
{ 
    int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printClosest(arr, n, x); 
    return 0; 
} 