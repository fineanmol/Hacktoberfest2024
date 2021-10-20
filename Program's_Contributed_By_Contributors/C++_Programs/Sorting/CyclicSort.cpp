// Introduction
------------------

// Cycle Sort is an in-place sorting algorithm.
// This sorting algorithm is best suited for situations where memory write or swap operations are costly. 

// 1. We first consider the cycle that includes first element. 
// 2. We find correct position of first element, place it at its correct position, say j. 
// 3. We consider old value of arr[j] and find its correct position, we keep doing this till all elements of current cycle are placed at correct position, i.e., we don’t come back to cycle starting point.


------------------
// TIME COMPLEXITIES
------------------------
// Worst-case performance     O(n^2)
// Best-case performance      O(n)
// Average performance        O(n^2)
------------------------

// SPACE COMPLEXITIES
------------------------
// Worst-case performance       O(1)
------------------------


#include <algorithm>
#include <iostream>
using namespace std;

  

// Function to sort arr[] of
// size n using cyclic sort   
 void Cyclic_sort(int arr[],int n) {
        
        int i=1;
        
        while(i<n){
            
            //find the correct postion of the element
            //eg: 1 will be in 0 index
            int correct_position = arr[i]-1;
            

            //if the element is not in it's correct position
            // swap it with the element present in its correct postion.
            if(arr[i]!=arr[correct_position]){

                 swap(arr[i], arr[correct_position]);
                
            }
            //if it is in correct position increment the i index
            else{
                i++;
            }
            
        }
  
  }

// Driver code
int main()
{
    int arr[] = {1 , 3 , 2 , 4 , 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    Cyclic_sort(arr,n);
 
    cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
-----------------------------------------------
