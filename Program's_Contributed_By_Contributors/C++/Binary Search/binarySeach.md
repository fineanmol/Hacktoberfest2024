# Binary Search
## **Sorting Algorithm**

**Binary Search** is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 

<br><hr>

## **Algorithm**

**Binary Search Algorithm**: The basic steps to perform Binary Search are:

* Begin with the mid element of the whole array as a search key.
* If the value of the search key is equal to the item then return an index of the search key.
*  Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
* Otherwise, narrow it to the upper half.
Repeatedly check from the second point until the value is found or the interval is empty.

<hr>

![binary-search-algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20220309171621/BinarySearch.png)


Binary Search is a method to find the required element in a sorted array by repeatedly halving the array and searching in the half.

This method is done by starting with the whole array. Then it is halved. If the required data value is greater than the element at the middle of the array, then the upper half of the array is considered. Otherwise, the lower half is considered. This is done continuously until either the required data value is obtained or the remaining array is empty.

A program that demonstrates binary search in C++ is given below.

## **Code Implementation**
```cpp 
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
         return mid ;
      if (arr[mid] > num)
         return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
         return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}
int main(void) {
   int arr[] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int num;
   cout << "Enter the number to search: \n";
   cin >> num;
   int index = binarySearch (arr, 0, n-1, num);
   if(index == -1){
      cout<< num <<" is not present in the array";
   }else{
      cout<< num <<" is present at index "<< index <<" in the array";
   }
   return 0;
}
```
**Output**
```

Enter the number to search
20
20 is present at index 5 in the array
```

<br>

## **Resources:**
<br>

* [**TUTORIALPOINT**](https://www.tutorialspoint.com/binary-search-in-cplusplus)
* [**GFG**](https://www.geeksforgeeks.org/binary-search/)
