// Bubble sort 

#include<stdio.h>
int main()
{
int array[10], n, i, j, swap; 
printf("Enter the numbers : ");
for(i=0;i<=9;i++)
scanf("%d", &array[i]); 
for(i = 0 ; i <10; i++)
{
for(j = 0 ; j < 9-i; j++)
{
if(array[j] > array[j+1]) 
{
swap=array[j];
array[j]=array[j+1];
array[j+1]=swap;
}
}
} 
printf("Sorted Array:"); 
for(i = 0; i < 10; i++)
printf("%d\n", array[i]);
return 0;
}
