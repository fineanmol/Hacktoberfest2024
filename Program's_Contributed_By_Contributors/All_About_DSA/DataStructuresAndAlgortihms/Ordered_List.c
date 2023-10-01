#include <stdio.h>

int insert(int a[],int element,int n){
    int key,i,j=0;
    a[n] = element;
    for (j=1;j<n+1;j++){
        key = a[j];
        i = j-1;
        while ((i>=0)&&(a[i]>key)){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
    return 0;
}
int delete(int a[],int size,int index){
    for (int i=index;i<size-1;i++){
        a[i] = a[i+1];
    }
}
int display(int a[],int size){
    for (int i = 0;i<size;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}
int search(int a[],int element,int size,int flag){
    for (int i=0;i<size;i++){
        if (a[i]==element){
            flag = i;
        }
    }
    return flag;
}
int main(){
    int n,choice,size,index,element,flag;
    printf("Enter the size of the list : ");
    scanf("%d",&n);
    printf("    -----------   ORDERED LIST   ----------   \n");
    printf("    -----------   MENU    ----------   \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("5. Exit\n");

    int a[n];
    size = 0;
    while (choice!=5){
        printf(" ---- COMMAND ---- ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        if (size+1>n){
            printf("LIST IS FULL !\n");
        }
        else{
            int element;
            printf("Enter the element : ");
            scanf("%d",&element);
            insert(a,element,size);
            size = size+1;
        }
        break;
        case 2:
        if (size==0){
            printf("EMPTY LIST !\n");
        }
        else{
            printf("Enter the index : ");
            scanf("%d",&index);
            if ((index<0)||(index>size)){
                printf("Please enter a valid input !\n");
            }
            else{
                delete(a,size,index);
                size = size-1;
            }
        }
        break;
        case 3:
        if (size==0){
            printf("EMPTY LIST !\n");
        }
        else{
            display(a,size);
        }
        break;
        case 4:
        printf("Enter the element : ");
        scanf("%d",&element);
        flag = -1;
        flag = search(a,element,size,flag);
        if (flag!=-1){
            printf("Element found at %d\n",flag);
        }
        else{
            printf("Element not found\n");
        }
        break;
        case 5:
        break;
        default:
        printf("Please enter a valid input !\n");
        }
    }
}