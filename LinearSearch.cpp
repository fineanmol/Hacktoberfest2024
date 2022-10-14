// To search an element in the given array/ list. 
// Time Complexity: O(n)

// Demo in C++:
// Given array, arr[4] = {2, 3, 4, 5}

#include <bits/stdc++.h>
using namespace std;

int main() {
  
  cout << "Enter the element you want to search: ";
  int num;
  cin>>num;
  
  vector<int> arr {2, 3, 4, 5};
  
  int n = arr.size();
  
  for (int i=0; i<n; i++) {
    
    if (arr[i] == num) {
      cout << i;
      return 0;
    }
    
  }
  
  cout<< "Element not found!";
  return 0;
  
}
