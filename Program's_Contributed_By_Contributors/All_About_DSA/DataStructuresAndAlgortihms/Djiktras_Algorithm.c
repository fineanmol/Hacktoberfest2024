#include <stdio.h>
#include <stdlib.h>

int main(){
    int v;
    printf("Enter the number of vertices : ");
    scanf("%d",&v);
    printf("-------DJIKTRAS ALGORITHM-------\n");
    printf("-------MENU--------\n");
    printf("1. Insert a Graph\n");
    printf("2. Display Matrix\n");
    printf("3. Find Shortest Path\n");
    printf("4. Exit\n");

    int e,v1,v2,choice=0,flag=0;
    int matrix[v][v];
    while (choice!=4){
        printf("Enter your command ---- ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Edges : ");
            scanf("%d",&e);
            for (int i=0;i<v;i++){
                for (int j=0;j<v;j++){
                    matrix[i][j] = 99;
                }
            }
            for (int i=0;i<e;i++){
                printf("Enter starting vertex : ");
                scanf("%d",&v1);
                printf("Enter end vertex : ");
                scanf("%d",&v2);
                printf("Enter the cost : ");
                scanf("%d",&matrix[v1-1][v2-1]);
            }
            flag = 1;
            break;
            case 2:
            if (flag==0){
                printf("Enter a graph!\n");
            }
            else{
                for (int i=0;i<v;i++){
                    for (int j=0;j<v;j++){
                        printf("%d ",matrix[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
            case 3:
            if (flag==0){
                printf("Please enter a graph!\n");
            }
            else{
                for (int k=0;k<v;k++){
                    for (int i=0;i<v;i++){
                        for (int j=0;j<v;j++){
                            if(matrix[i][j]>matrix[i][k]+matrix[k][j]){
                                matrix[i][j] = matrix[i][k] + matrix[k][j];
                            }
                        }
                    }
                }
                printf("Adjacency matrix converted to shortest distance between any two vertex\n");
            }
            break;
            case 4:
            printf("----Exiting----\n");
            break;
            default:
            printf("Please enter a valid input!\n");
        }
    }
    return 0;
}