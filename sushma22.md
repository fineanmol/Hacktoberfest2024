#include<stdio.h>
int main()
{
	int i,j,n,temp,num[50];
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
    printf("enter %d integers\n",n);
    for(i=0;i<n;i++)
    {
    	scanf("%d",&num[i]);
    }
     for(i=0;i<n;i++)
     {
     	 for(j=0;j<n;j++)
     	 {
     	 	if(num[i]>num[j])
     	 	{
     	 		temp=num[i];
     	 		num[i]=num[j];
     	 		num[j]=temp;
			  }
		  }
	 }
	 printf("sorted elements \n ");
	  for(i=0;i<n;i++)
	  printf("%d\n",num[i]);
}
