//wap to print armstrong number
#include<stdio.h>
#include<math.h>
void main()
{
	int n,i,c=0,sum=0;
	printf("enter a number"); 
	scanf("%d",&n);
	i=n;
	for(i;i>0;i/=10)
	{
		c++;
		
	}
	i=n;
	while(i!=0)
	{
		sum=sum+pow(i%10,c);
		i/=10;
		
	}
	if(sum==n)
	printf("%d is armstrong",n);
	else
	printf("%d is not armstrong",n);
}
