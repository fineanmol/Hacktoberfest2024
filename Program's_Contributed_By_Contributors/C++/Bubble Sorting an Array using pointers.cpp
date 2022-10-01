#include <stdio.h>
void main(){
    int *a,i,j,t,n;
    printf("Size of Array : ");
    scanf("%d",&n);
    printf("Give Array Elements: ");
    for(i=0;i<n;i++){
        scanf("%d",a+i);
        }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(*(a+i) > *(a+j)){
                t = *(a+i);*(a+i) = *(a+j);
                *(a+j) = t;
            }
        }
    }
    printf("Sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",*(a+i));
    }
}
