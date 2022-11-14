//C++ program for Kandane_algorithm

// The idea of Kadane’s algorithm is to maintain a variable max_ending_
// here that stores the maximum sum contiguous subarray ending at current index and a variable
//  max_so_far stores the maximum sum of contiguous subarray found so far, Everytime there is a positive-sum value 
//  in max_ending_here compare it with max_so_far and update max_so_far if it is greater than max_so_far.


#include<iostream>

using namespace std;

//funtion to find highest max  in a array
int kadanes(int array[],int length) {
   int highestMax = 0;
   int currentElementMax = 0;
   for(int i = 0; i < length; i++){
      currentElementMax =max(array[i],currentElementMax + array[i]) ;
      highestMax = max(highestMax,currentElementMax);
   }
   return highestMax;
}

// main function

int main() {
   cout << "Enter the array length: ";
   int l;
   cin >> l;
   int arr[l];
   cout << "Enter the elements of array: ";
   for (int i = 0; i < l; i++) {
      cin >> arr[i];
   }
   cout << "The Maximum Sum is: "<<kadanes(arr,l) << endl;
   return 0;
}