#include <stdio.h>
int main()
{
	int n,i,sum=0;
	printf("enter the limit");
	scanf("%d",&n);
	for(i=1;i<=n;i+=2)
	{
		sum=sum+i;
	}
	printf("Sum=%d",sum);
}
