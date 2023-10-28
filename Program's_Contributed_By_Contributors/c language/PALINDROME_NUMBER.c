//wap to print palindrome number or not
#include<stdio.h>
void main()
{
	int n,i,sum=0;
	printf("enter a number");
	scanf("%d",&n);
	i=n;
	while(i>0)
	{
		sum=sum*10+(i%10);
		i=i/10;
	}
	if(n==sum)
	printf("%d is palindrome",n);
	else 
	printf("%d is not palindrome",n);
}
