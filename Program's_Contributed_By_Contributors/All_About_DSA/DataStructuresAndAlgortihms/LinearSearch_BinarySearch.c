#include <stdio.h>
int create_list(int a[],int n){
    int element,i;
    for (i = 0;i<n;i++){
        printf("Enter the element : ");
        scanf("%d",&element);
        a[i] = element;
    }
    return 0;
}
int display(int a[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
int linear_search(int a[],int n){
    int i,element,pos=-1;
    printf("Enter the element to be searched : ");
    scanf("%d",&element);
    for (int i=0;i<n;i++){
        if (a[i]==element){
            pos=i;
            printf("Element Found at %d !\n",pos);
        }
    }
    if (pos==-1){
        printf("Element Not Found !\n");
    }
    return 0;
}
int selection_sort(int a[],int n){
    int i,j,min,t;
    for (i=0;i<n-1;i++){
        min = i;
        for (j=i+1;j<n;j++){
            if (a[j]<a[min]){
                min = j;
            }
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
    return 0;
}
int binary_search(int a[],int LB,int UB,int element){
    int i,q,flag = 0;
    while (LB<=UB){
        q = (LB+UB)/2;
        if (a[q]==element){
            printf("Element found at %d !\n",q);
            flag = 1;
            break;
        }
        else if (a[q]>element){
            UB = q-1;
        }
        else{
            LB = q+1;
        }
    }
    return flag;
}
int main(){
    int n,element;
    printf("Enter the size : ");
    scanf("%d",&n);
    if (n<0){
        printf("Please enter a valid length !\n");
    }
    else{
        printf("--------MENU--------\n");
        printf("1. Enter a numerical list\n");
        printf("2. Display\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search\n");
        printf("5. Exit\n");
        int a[n];
        int flag2,choice=0,flag=0;
        while (choice!=5){
            printf("Enter the Choice : ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                create_list(a,n);
                flag=1;
                break;
                case 2:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    display(a,n);
                }
                break;
                case 3:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    linear_search(a,n);
                }
                break;
                case 4:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    printf("Enter the element to be searched for : ");
                    scanf("%d",&element);
                    selection_sort(a,n);
                    flag2 = binary_search(a,0,n-1,element);
                    if (flag2==0){
                        printf("Element not found !\n");
                    }
                }
                break;
                case 5:
                printf("--------Exiting--------\n");
                break;
                default:
                printf("Please enter a valid input !\n");
            }
        }
    }
    return 0;
}