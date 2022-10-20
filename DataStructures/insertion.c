#include <stdio.h>
void quicksort(int number[25],int first,int last){
 int i, j, pivot, temp;
 if(first<last){
 pivot=first;
 i=first;
 j=last;
 while(i<j){
 while(number[i]<=number[pivot]&&i<last)
 i++;
 while(number[j]>number[pivot])
 j--;
 if(i<j){
 temp=number[i];
 number[i]=number[j];
 number[j]=temp;
 }
 }
 temp=number[pivot];
 number[pivot]=number[j];
 number[j]=temp;
 quicksort(number,first,j-1);
 quicksort(number,j+1,last);
 }
}
int main()
{
 int n, i, j, position, temp;
 printf(" Enter number of elements : ");
 scanf("%d", &n);
 int *a;
 a= (int*) malloc(n * sizeof(int));
 printf(" Enter elements : ");
 for (i = 0; i < n; i++)
 scanf("%d", &a[i]);
 quicksort(a,0,n-1); 
 printf("\n Sorted Array: ");
 for(i = 0; i < n; i++)
 printf("%d ", a[i]);
 return 0;
}
