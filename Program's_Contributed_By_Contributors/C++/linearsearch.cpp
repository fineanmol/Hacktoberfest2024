// Linear Search in C++

#include <iostream>
using namespace std;

int search(int array[], int n, int x) {

  // 
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 1;
  int n = sizeof(array) / sizeof(array[0]);

  int result = search(array, n, x);

  (result == -1) ? cout << "Element is not found in the array" : cout << "Element found at index: " << result << "!!";

  return 0;
}