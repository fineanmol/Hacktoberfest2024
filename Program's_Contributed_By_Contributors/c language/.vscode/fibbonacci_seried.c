#include<stdio.h>
int main()
{
	int n1,n2,n3,i,n;
	printf("ENTER THE NUMBER OF ELEMENTS");
	scanf("%d",&n);
	printf("first element");
	scanf("%d%d",&n1,&n2);
	for(i=0;i<n-2;++i)
	{
		n3=n1+n2;
		printf("%d ",n3);
		n1=n2;
		n2=n3;
	}
	return 0;
	
}
