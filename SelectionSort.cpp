/*  
Selection sort is a sorting algorithm that selects the smallest element 
from an unsorted list in each iteration and places that element at the beginning of the unsorted list.
Time Complexity: O(n^2)
Space Complexity: O(1)
Contributor: @whyanujjwhy
*/

// Selection sort in C++
#include<iostream>
using namespace std;

//function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//function to print an array
void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//selection sort functionality
void selectionSort(int arr[], int n) {
  for(int step = 0; step < n - 1; step++) {
    int min_idx = step;
    for(int i = step + 1; i < n; i++) {

      // Select the minimum element in each loop.
      if (arr[i] < arr[min_idx])
        min_idx = i;
    }

    // min at the correct pos
    swap(&arr[min_idx], &arr[step]);
  }
}

// driver function
int main() {
  int n;
  cout<<"Enter size of array: ";      //user input for size of array
  cin>>n;
  int data[n];
  cout<<"\nEnter space-separated "<<n<<" elements for sorting: ";
  for(int i=0; i<n; i++)             //loop for arrat element input  [we can also initialise the array] 
    cin>>data[i];
  selectionSort(data, n);
  cout << "Sorted array in Acsending Order:\n";
  printArr(data, n);
}
