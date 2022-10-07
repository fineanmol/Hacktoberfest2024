//Bubblesort using Pointers and Dynamic programming
#include <stdio.h>
#include <stdlib.h>

void allocate(int *a,int len){
    for (int i=0;i<len;i++){
        printf("\nEnter Element :");
        scanf("%d",(a+i));
    }
}
void display(int *a,int len){
    printf("\nSorted Elements :");
    for (int i=0;i<len;i++){
        printf("\t%d",*(a+i));
    }
}

void bubblesort(int *a,int len){
  int i,j;
    for(i=0;i<len-1;i++){
      for (j = 0; j <len-i-1 ; j++) {
        if (*(a+j)>*(a+j+1)) {
          int temp=*(a+j);
          *(a+j)=*(a+j+1);
          *(a+j+1)=temp;
        }
      }
    }
  }


void main()
{
    int *ary;
    int len;
    printf("Enter Length Of Array : ");
    scanf("%d",&len);
    ary=(int*)calloc(len,sizeof(int));
    allocate(ary,len);
    bubblesort(ary,len);
    display(ary,len);

}
