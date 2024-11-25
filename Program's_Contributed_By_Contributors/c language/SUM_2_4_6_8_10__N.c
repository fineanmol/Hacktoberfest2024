#include <stdio.h>
void main()
{
	int n,i,sum=0;
	printf("enter the limit");
	scanf("%d",&n);
	for(i=2;i<=n;i+=2)
	{
		sum=sum+i;
	}
	printf("Sum=%d",sum);
}
