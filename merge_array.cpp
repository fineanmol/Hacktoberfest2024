#include <iostream>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;
void mergeSortedArrays(int *arr1, int n1, int *arr2, int n2, int *result){
   int i, j, k;
   i = 0;
   j = 0;
   k = 0;
   while (i < n1 && j < n2) {
      if (arr1[i] < arr2[j]) {
         result[k] = arr1[i];
         ++k;
         ++i;
      } else {
         result[k] = arr2[j];
         ++k;
         ++j;
      }
   }
   while (i < n1) {
      result[k] = arr1[i];
      ++k;
      ++i;
   }
   while (j < n2) {
      result[k] = arr2[j];
      ++k;
      ++j;
   }
}
void dispalyArray(int *arr, int n){
   for (int i = 0; i < n; ++i) {
      cout << arr[i] << " ";
   }
   cout << endl;
}
int main(){
   int arr1[] = {10, 15, 17, 20};
   int arr2[] = {5, 9, 7, 13, 19};
   int result[SIZE(arr1) + SIZE(arr2)];
   cout << "First sorted array:" << endl;
   dispalyArray(arr1, SIZE(arr1));
   cout << "Second sorted array:" << endl;
   dispalyArray(arr2, SIZE(arr2));
   mergeSortedArrays(arr1, SIZE(arr1), arr2, SIZE(arr2), result);
   cout << "Final sorted array:" << endl;
   dispalyArray(result, SIZE(result));
   return 0;
}
