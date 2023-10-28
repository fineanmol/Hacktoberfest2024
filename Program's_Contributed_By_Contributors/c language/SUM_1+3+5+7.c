#include <stdio.h>
void main()
{
	int n,i,sum=0;
	print ("enter the limit");
	scanf("%d",&n);
	for(i=1;i<=n;i+=2)
	{
		sum=sum+i;
	}
	printf("Sum=%d",sum);
}
