#include<stdio.h>
int main()
{
	int i,j,n=5;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		printf(" ");
		for(j=0;j<(2*i-1);j++)
		printf("*");
		printf("\n");
	}
}
