#include <bits/stdc++.h> 
using namespace std; 
  



int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
      
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid
        
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  

    // not found
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = { 1,2, 3, 4, 5,6,7,8,9 10}; 
    int x = 8; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
    return 0; 
} 
