#include <stdio.h>

void main(){
    int mat[10][10], i, j, row, column;
    
    // Enter the size of matrix
    printf("Enter Row and Column for Matrix : ");
    scanf("%d%d", &row,&column);
    
    // Enter number in matrix
    printf("Enter %d numbers : ", row * column);
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    // Show all the elements of matrix
    printf("Elements of Mtrix are : \n");
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
    
    // Find even elements inside a matrix
    printf("Even numbers in matrix are : \t");
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            if(mat[i][j]%2 == 0)
                printf("%d \t", mat[i][j]);
        }
    }
}
