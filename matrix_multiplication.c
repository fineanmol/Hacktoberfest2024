#include<stdio.h>
int main(){
    int a,b,m,n;
    printf("enter the no. of elements of matA and matB\n");
    scanf("%d%d%d%d",&a,&b,&m,&n);
    //checking the condition if the matrices are valid or not
    if(b!=m)
    {
    	printf("the matrices are not suitable for multiplication\n");
    	return -1;
	}
	//if the matrices are valid for multiplication then input the elements of the matrices
	int matA[a][b],matB[m][n],i,j,k,mult=0;
	printf("enter the elements of matA\n");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%d",&matA[i][j]);
		}
	}
	printf("enter the elements of matB\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matB[i][j]);
		}
	}
	// code for matrix multiplication
	for(i=0;i<a;i++){
		for(k=0;k<n;k++){
			for(j=0;j<b;j++){
				mult+=(matA[i][j]*matB[j][k]);
			}
			printf("%d ",mult);
			mult=0;
 		}
	}
}
