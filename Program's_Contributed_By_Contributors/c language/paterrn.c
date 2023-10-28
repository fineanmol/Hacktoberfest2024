#include<stdio.h>
void main (){
	int row,i,j;
	printf("enter row ");
	scanf("%d",&row);
	for( i=1; i<=row;i++){
		for( j=1; j<=2*row-1; j++)
			{		
				if(j<=row-(i-1)&&j<=row+(i-1))
					printf("*");
				else
					printf(" ");
	}
		printf("\n");
	}
	
}
