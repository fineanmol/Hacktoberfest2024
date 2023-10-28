#include<stdio.h>
void tower(int,char,char,char);
int main()
{
	int n;
	printf("Enter number of disk for the\n\tTower of Hannoi\n");
	scanf("%d",&n);
	tower(n,'A','B','C');
	return 0;
}
void tower(int n, char source,char spare, char dest)
{
	if(n==1)
		printf("\n Move form %c to %c",source,dest);
	else
	{
		tower(n-1,source,dest,spare);
		
		tower(1,source,spare,dest);
		
		tower(n-1,spare,source,dest);
	}
}
