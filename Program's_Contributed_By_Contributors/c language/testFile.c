
#include <stdio.h>
#include <String.h>
int main()
{
	int a[3]={10,200,3000};
	int i, *p;
	p=a;
	printf("%d\n",p);	
	for(i=0;i<3;i++)
	{
		printf("adress\t%d\t",p);
		printf("value\t%d\n",*p);
		p++;
	}
}
