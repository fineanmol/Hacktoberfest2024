#include <stdio.h>
void main()
{
	int n,i,sum=0;
	printf("enter the limit");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if (i % 2 == 1)
            sum=sum+i;
        else 
            sum=sum-i;		
	}
	printf("Sum=%d",sum);
}
/*
sum=sum-i*pow((-1),i);
this takes more time
*/

