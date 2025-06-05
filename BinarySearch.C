#include <stdio.h>
#include<stdlib.h>
int binaryScr(int a[], int low, int high, int m)
{
if (high >= low) {
int mid = low + (high - low) / 2;
if (a[mid] == m)
return mid;
if(a[mid] > m)
return binaryScr(a, low, mid - 1, m);
return binaryScr(a, mid + 1, high, m);
}
return -1;
}
int main(void)
{
int a[] = { 12, 13, 21, 36, 40 };
int i,m;
for(i=0;i<5;i++)
{
printf(" %d",a[i]);
}
printf(" n");
int n = sizeof(a) / sizeof(a[0]);
printf("Enter the number to be searchedn");
scanf("%d", &m);
int result = binaryScr(a, 0, n - 1, m);
(result == -1) ? printf("The element is not present in array")
printf("The element is present at index %d",
result);
return 0;
}
