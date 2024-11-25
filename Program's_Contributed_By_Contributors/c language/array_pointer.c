#include <stdio.h>
int main()
{
	
	int i,x[5],*c;
	 for(i=0;i<5;i++)
	{
		c=&x[i];
		printf("%d\t",c);//the adderess has a diffference
	}
	return 0;
}
