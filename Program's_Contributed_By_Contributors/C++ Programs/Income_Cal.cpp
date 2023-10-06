#include<stdio.h>
int main()
{
	int mi,ai,total;
	printf("enter monthly income of your father :");
	scanf("%d",&mi);
	ai=mi*12;
	printf("\n total annual income= %d",ai);
	
		if (ai>100000)
		{
		printf("\n annual income including 10 percentage reward : %d" , (total=(mi*12)+ai*10/100));
	}
	    else if (ai<100000)
	{
		printf("\n annual income including 20 percentage reward : %d", (total=(mi*12)+ai*20/100));
	}
}
