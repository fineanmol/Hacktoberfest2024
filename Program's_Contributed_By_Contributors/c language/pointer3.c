#include<stdio.h>
void main()
{
	int x[5]={1,2,56,54,5};
	int *ptr=&x[2];
	printf("%d ",*ptr);
	printf("%d ",*(ptr-1));
	printf("%d ",*(ptr-2));
	printf("%d ",*(ptr+1));
	printf("%d ",*(ptr+2));
		
}
