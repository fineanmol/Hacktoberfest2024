#include<stdio.h>
#include<process.h>
int main(){
int a[10][10],b[10][10],c[10][10]; // Array_name [row][column]
int i,j,m,n,p,q;
printf("Enter row and column of matrix A \n");
scanf("%d %d",&m,&n);               // reading row then column
printf("Enter row and column of matrix B \n");
scanf("%d %d",&p,&q);               // reading row then column

if((m==p)&&(n==q))                  // checks whether the row and column are equal
    printf("Matrices can be subtracted\n");
else
    {
        printf("Martices cannot be subtracted\n");  //message and exit if they are not equal
        exit(0);
    }

printf("\nEnter the values for matrix A \n");       // enter A[][] if the operation is possible

for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
     scanf("%d",&a[i][j]);
}

printf("\nEnter the values for matrix B \n");       // enter B[][] if the operation is possible
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
        scanf("%d",&b[i][j]);
}

for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
      c[i][j]=a[i][j]-b[i][j];

}
printf("\nDifference A-B=C is :\n");            //finding the difference

for(i=0;i<p;i++)                                // printing the difference
{   printf("\n");
    for(j=0;j<q;j++)
        printf(" %d",c[i][j]);
}
return 0;
}