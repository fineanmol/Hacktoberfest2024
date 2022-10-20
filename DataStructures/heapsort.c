#include<stdio.h>
void heapify(int arr[], int n, int i)
{
 int largest = i;
 int l = 2 * i + 1;
 int r = 2 * i + 2;
 if (l < n && arr[l] > arr[largest])
 largest = l;
 if (r < n && arr[r] > arr[largest])
 largest = r;
 if (largest != i) {
 int tmp=arr[largest];
 arr[largest]=arr[i];
 arr[i]=tmp;
 heapify(arr, n, largest);
 }
}
void heapSort(int arr[], int n)
{
 int i;
 for (i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i);
 for (i = n - 1; i > 0; i--) {
 int tmp=arr[0];
 arr[0]=arr[i];
 arr[i]=tmp;
 heapify(arr, i, 0);
 }
}
int main()
{
 int n, i;
 printf(" Enter number of elements : ");
 scanf("%d", &n);
 int *a;
 a= (int*) malloc(n * sizeof(int));
 printf(" Enter elements : ");
 for (i = 0; i < n; i++)
 scanf("%d", &a[i]);
 heapSort(a,n);
 printf("\n Sorted Array: ");
 for(i = 0; i < n; i++) 
 printf("%d ", a[i]);
 return 0;
} 
