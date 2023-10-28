#include <stdio.h>
void main()
{
	int n,c,i,sum=0;
	printf("enter the limit and the constant\n");
	scanf("%d\n%d",&n,&c);
	for(i=1;i<=n;i++)
	{
		sum=sum+i*c;
	}
	printf("Sum=%d",sum);
}
