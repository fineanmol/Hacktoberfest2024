#include <stdio.h>
int SequentialSearch (int lenght, int vector[], int x)
{
	int i;
	for (i=0; i < lenght; i++)
		if (vector[i] == x)
			return i;
		return -1;
}

int main()
{
	int v[8]={8,4,0,7,3,4,6,5};
	int fun, x;
	printf("Put the value to be found: ");
	scanf("%d",&x);
	fun = SequentialSearch(8,v,x);
	if (fun == -1)
		printf("Value not found");
	else
		printf("Found at position %d of the vector ", fun);
	return 0;
}
