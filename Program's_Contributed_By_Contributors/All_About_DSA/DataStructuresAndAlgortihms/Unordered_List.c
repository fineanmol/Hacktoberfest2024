#include <stdio.h>
int Menu(){
    int input;
    printf(" -- COMMAND -- ");
    scanf("%d",&input);
    return input;
}
void insert(int a[],int size,int element){
    a[size] = element;
}
void delete (int a[],int size,int index){
    int i;
    for (i=index;i<size-1;i++){
        a[i] = a[i+1];
    }
}
void display(int a[],int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}
int search(int a[],int size,int element){
    int i=0,flag=-1;
    for (i=0;i<size;i++){
        if (a[i]==element){
            flag = i;
            break;
        }
    }
    return flag;
}

int main(){
    int choice,n,size;
    printf("Enter the maximum size of the list : ");
    scanf("%d",&n);
    printf("    -----------   UNORDERED LIST   ----------   \n");
    printf("    -----------   MENU    ----------   \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("5. Exit\n");
    
    int a[n];
    size = 0;
    if (n>0){
        do{
            choice = Menu();
            switch (choice){
                case 1:
                if (size+1>n){
                    printf("LIST FULL\n");
                }
                else{
                    int element;
                    printf("Enter the element : ");
                    scanf("%d",&element);
                    insert(a,size,element);
                    size = size+1;
                }
                break;
                case 2:
                if (size-1<0){
                    printf("EMPTY LIST\n");
                }
                else{
                    int index;
                    printf("Enter the index : ");
                    scanf("%d",&index);
                    if ((index>-1)&&(index<size)){
                        delete(a,size,index);
                        size = size-1;
                    }
                    else{
                        printf("Enter a valid index!\n");
                    }
                }
                break;
                case 3:
                if (size==0){
                    printf("EMPTY LIST\n");
                }
                else{
                    display(a,size);
                }
                break;
                case 4:
                int flag;
                if (size==0){
                    printf("EMPTY LIST\n");
                }
                else{
                    int searcher;
                    printf("Enter the element to be searched : ");
                    scanf("%d",&searcher);
                    flag = search(a,size,searcher);
                    if (flag!=-1){
                        printf("Element Found at %d\n",flag);
                    }
                    else{
                        printf("Element Not Found\n");
                    }
                }
                break;
                case 5:
                break;
                default:
                printf("Please Enter a Valid Input\n");
            }
        }
        while (choice!=5);       
    }
    else{
        printf("Length cannot be negative\n");
    }
    return 0;
}