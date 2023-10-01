#include <stdio.h>

int create_list(int a[],int n){
    int i,element;
    for (i=0;i<n;i++){
        printf("Enter the element : ");
        scanf("%d",&element);
        a[i] = element;
    }
    return 0;
}
int display(int a[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
int swap(int a[],int i,int j){
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
    return 0;
}
int quick_sort_first(int a[],int LB,int UB){
    int i,j,key,flag=1;
    if (LB<UB){
        i = LB;
        j = UB+1;
        key = a[i];
        while (flag==1){
            i = i+1;
            while (a[i]<key){
                i = i+1;
            }
            j = j-1;
            while (a[j]>key){
                j = j-1;
            }
            if (i<j){
                swap(a,i,j);
            }
            else{
                flag=0;
            }
        }
        swap(a,LB,j);
        quick_sort_first(a,LB,j-1);
        quick_sort_first(a,j+1,UB);
    }
    return 0;
}
int quick_sort_last(int a[],int LB,int UB){
    int i,j,key,flag=1;
    if (LB<UB){
        i = LB-1;
        j = UB;
        key = a[j];
        while (flag==1){
            i = i+1;
            while (a[i]<key){
                i = i+1;
            }
            j = j-1;
            while (a[j]>key){
                j = j-1;
            }
            if (i<j){
                swap(a,i,j);
            }
            else{
                flag = 0;
            }
        }
        swap(a,i,UB);
        quick_sort_last(a,LB,i-1);
        quick_sort_last(a,i+1,UB);
    }
    return 0;
}
int quick_sort_middle(int a[],int LB,int UB){
    int i,j,key,flag=1;
    if (LB<UB){
        key = (LB+UB)/2;
        swap(a,key,LB);
        i = LB;
        j = UB+1;
        key = a[i];
        while (flag==1){
            i = i+1;
            while (a[i]<key){
                i=i+1;
            }
            j = j-1;
            while (a[j]>key){
                j = j-1;
            }
            if (i<j){
                swap(a,i,j);
            }
            else{
                flag=0;
            }
        }
        swap(a,LB,j);
        quick_sort_middle(a,LB,j-1);
        quick_sort_middle(a,j+1,UB);
    }
    return 0;
}
int merge(int a[],int p,int q,int r){
    int n1 = q-p+1, n2 = r-q;
    int L[n1+1],R[n2+1];
    int i,j=0;
    for (i=p;i<q+1;i++){
        L[j] = a[i];
        j++;
    }
    j=0;
    for (i=q+1;i<=r;i++){
        R[j] = a[i];
        j++;
    }
    L[n1] = 2147483647;
    R[n2] = 2147483647;
    i=0;
    j=0;
    for (int k=p;k<=r;k++){
        if (L[i]<=R[j]){
            a[k] = L[i];
            i = i+1;
        }
        else{
            a[k] = R[j];
            j = j+1;
        }
    }
    return 0;
}
int merge_sort(int a[],int p,int r){
    int q;
    if (p<r){
        q = (p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
    return 0;
}
int main(){
    int n;
    printf("Enter the Size :");
    scanf("%d",&n);
    if (n<0){
        printf("Please enter a valid length !\n");
    }
    else{
        printf("--------MENU--------\n");
        printf("1. Enter a List\n");
        printf("2. Display\n");
        printf("3. Quick Sort with First Element as Pivot\n");
        printf("4. Quick Sort with Last Element as Pivot\n");
        printf("5. Quick Sort with Middle Element as Pivot\n");
        printf("6. Merge Sort\n");
        printf("7. Exit\n");

        int a[n];
        int choice,flag=0;
        while (choice!=7){
            printf("Enter the command : ");
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
                    quick_sort_first(a,0,n-1);
                }
                break;
                case 4:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    quick_sort_last(a,0,n-1);
                }
                break;
                case 5:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    quick_sort_middle(a,0,n-1);
                }
                break;
                case 6:
                if (flag==0){
                    printf("Please enter a list !\n");
                }
                else{
                    merge_sort(a,0,n-1);
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