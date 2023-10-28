#include <stdio.h>
void main()
{
	int *pc,c;
	pc=&c;
	printf("%d\n",pc);
	c=10;
	pc=&c;
	printf("%d",pc);
}
