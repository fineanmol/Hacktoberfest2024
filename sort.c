#include <stdio.h>

int insertion_sort(int arr[], int n) {
  int comparisons = 0;
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
      comparisons++;
    }
    arr[j + 1] = key;
  }
  return comparisons;
}

void print_sorted_array(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }
}


int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int comparisons = insertion_sort(arr, n);
  printf("Number of comparisons: %d\n", comparisons);

  print_sorted_array(arr, n);

  return 0;
}
