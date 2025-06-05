#include <stdio.h>
#include <stdlib.h>

// Function to input an array from the user
int* inputArray(int size) {
  int* arr = (int*)malloc(size * sizeof(int));
  printf("Enter %d elements for the array:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  return arr;
}

// Merge two sorted arrays into a new sorted array
int* mergeArrays(int* arr1, int size1, int* arr2, int size2) {
  int* merged = (int*)malloc((size1 + size2) * sizeof(int));
  int i = 0, j = 0, k = 0;
  while (i < size1 && j < size2) {
    if (arr1[i] < arr2[j] || arr1[i] < 0) {
      merged[k++] = arr1[i++];
    } else {
      merged[k++] = arr2[j++];
    }
  }
  while (i < size1) {
    merged[k++] = arr1[i++];
  }
  while (j < size2) {
    merged[k++] = arr2[j++];
  }
  return merged;
}

// Merge a collection of sorted arrays into a single sorted array
int* mergeSortedArrays(int** arrays, int* sizes, int numArrays, int* mergedSize) {
  if (numArrays == 0) {
    *mergedSize = 0;
    return NULL;
  }
  int* merged = arrays[0];
  *mergedSize = sizes[0];
  for (int i = 1; i < numArrays; i++) {
    merged = mergeArrays(merged, *mergedSize, arrays[i], sizes[i]);
    *mergedSize += sizes[i];
  }
  return merged;
}
//Driver code / main function
int main() {
  int numArrays;

  // Getting inputs from the user for the arrays and their sizes

  printf("Enter the number of sorted arrays: ");
  scanf("%d", &numArrays);

  int* sizes = (int*)malloc(numArrays * sizeof(int));
  int** arrays = (int**)malloc(numArrays * sizeof(int*));

  for (int i = 0; i < numArrays; i++) {
    printf("Enter the size of array %d: ", i + 1);
    scanf("%d", &sizes[i]);
    arrays[i] = inputArray(sizes[i]);
  }

  int mergedSize;
  int* merged = mergeSortedArrays(arrays, sizes, numArrays, &mergedSize);

  printf("Merged and sorted array: ");
  for (int i = 0; i < mergedSize; i++) {
    printf("%d ", merged[i]);
  }
  printf("\n");

  // Free allocated memory
  for (int i = 0; i < numArrays; i++) {
    free(arrays[i]);
  }
  free(arrays);
  free(sizes);
  free(merged);
  return 0;
}
