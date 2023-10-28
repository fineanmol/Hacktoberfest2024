#include<stdio.h>
int main()
{
	int rows,i,j;
	printf("ENTER THE NUMBER OF ROWS");
	scanf("%d",&rows);
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows-1-i;j++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
}
