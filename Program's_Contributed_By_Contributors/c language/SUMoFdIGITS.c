// Wap to print the sum of digits
#include <stdio.h>
void main ()
{
	int n,sum=0;
	printf("ENTER A NUMBER");
	scanf("%d",&n);
	
	while(n!=0)
	{
		sum=sum+(n%10);
		n/=10;
	}
	printf("Sum=%d",sum);
}
