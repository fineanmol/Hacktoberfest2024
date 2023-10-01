#include <stdio.h>
int create_list(int a[],int n){
    int element;
    for (int i=0;i<n;i++){
        printf("Enter the Element : ");
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
int insertion_sort(int a[],int n){
    int i,j,key;
    for (i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while ((j>=0)&&(a[j]>key)){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
    printf("Sorted Array -- \n");
    display(a,n);
    return 0;
}
int bubble_sort(int a[],int n){
    int i,j,t,flag;
    for (i=0;i<n;i++){
        flag=0;
        for (j=0;j<n-1;j++){
            if (a[j]>a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = 1;
            }
        }
        if (flag==0){
            break;
        }
    }
    printf("Sorted Array --\n");
    display(a,n);
    return 0;
}
int selection_sort(int a[],int n){
    int i,j,t,min;
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
    printf("Sorted Array --\n");
    display(a,n);
    return 0;
}
int count_sort(int a[],int n){
    int max,i;
    max = a[0];
    for (i=1;i<n;i++){
        if (a[i]>max){
            max = a[i];
        }
    }

    int frequency[max+1];
    int sorted[n];
    for (i=0;i<max+1;i++){
        frequency[i] = 0;
    }
    for (i=0;i<n;i++){
        frequency[a[i]]++;
    }
    for (i=1;i<max+1;i++){
        frequency[i] = frequency[i]+frequency[i-1];
    }
    for (i=0;i<n;i++){
        sorted[frequency[a[i]]-1]=a[i];
    }
    printf("Sorted Array --\n");
    display(sorted,n);
    return 0;
}
int main(){
    int n;
    printf("Enter the Size : ");
    scanf("%d",&n);
    if (n<0){
        printf("Please enter a valid length !\n");
    }
    else{
        printf("--------MENU--------\n");
        printf("1. Enter the List\n");
        printf("2. Display\n");
        printf("3. Insertion Sort\n");
        printf("4. Bubble Sort\n");
        printf("5. Selection Sort\n");
        printf("6. Counting Sort\n");
        printf("7. Exit\n");
        int a[n];
        int choice,flag=0;
        while (choice!=7){
            printf("Enter the Command : ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                create_list(a,n);
                flag = 1;
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
                    insertion_sort(a,n);
                }
                break;
                case 4:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    bubble_sort(a,n);
                }
                break;
                case 5:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    selection_sort(a,n);
                }
                break;
                case 6:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    count_sort(a,n);
                }
                break;
                case 7:
                printf("--------Exiting--------\n");
                break;
                default:
                printf("Please enter a valid input !\n");
            }
        }
    }
    return 0;
}