#include <stdio.h>
void main()
{
	int n,i,sum=0;
	printf("enter the limit");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=sum+(i*i);
	}
	printf("Sum=%d",sum);
}
