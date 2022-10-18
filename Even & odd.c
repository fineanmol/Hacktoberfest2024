#include<stdio.h>
#include<conio.h>
int main()
{
	int n[5],i;
	printf("enter no.");
	for (i=0;i<=4;i++)
	{ scanf("%d",&n[i]);	
	}
	for (i=0;i<=4;i++)
	if (n[i]%2==0)
	{ 
	 printf("\n even %d",n[i]);
	}
	else
	{
		printf("\n odd %d",n[i]);
	}
	getch();
}

