//a program that prints a pattern. basic pattern 
#include<stdio.h>
int main()
{
	int i,j,k,a=7,b=2,c=10;
	for(i=0;i<3;i++)
	{
		for(j=1;j<=3;j++)
		printf("*");
		for(j=a;j>=1;j--)
		printf(" ");
		for(j=1;j<b;j++)
		printf("****");
		for(k=c;k>1;k--)
		printf(" ");
		for(j=1;j<b;j++)
		printf("****");
		for(j=a;j>=1;j--)
		printf(" ");
		for(j=1;j<=1;j++)
		printf("***");
		for(k=1;k<=6;k++)
		printf(" ");
		for(j=1;j<=1;j++)
		printf("***");
		a=a-2;
		b++;
		c=c-4;
		printf("\n");
	}
	a=3,b=25,c=7;
	for(i=0;i<6;i++)
	{
		for(j=1;j<=3;j++)
		printf("*");
		for(k=1;k<=a;k++)
		printf(" ");
		for(j=1;j<=b;j++)
		printf("*");
		for(k=1;k<=a;k++)
		printf(" ");
		for(j=1;j<=1;j++)
		printf("***");
		for(k=1;k<=6;k++)
		printf(" ");
		for(j=1;j<=1;j++)
		printf("***");
		a=a+2;
		b=b-4;
		printf("\n");
	}
	for(i=1;i<=1;i++)
	{
		for(j=1;j<=3;j++)
		printf("*");
		for(k=0;k<15;k++)
		printf(" ");
		for(j=0;j<1;j++)
		printf("*");
		for(k=0;k<18;k++)
		printf(" ");
		for(j=0;j<6;j++)
		printf("*");
	}
}