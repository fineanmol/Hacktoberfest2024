#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    printf("Enter the Size of Array: ");
    scanf("%d", &num);
    int c[num];
    arr = (int*) malloc(num * sizeof(int));
    printf("\nStart to Enter your nummbers Either use space or enter for different nos.\n");
    for(i = 0; i < num; i++) {
        scanf("%d", arr+i);
    }
    for(i=0;i<num/2;i++){
        c[i]=*(arr+i);
        *(arr+i)=*(arr+num-1-i);
        *(arr+num-1-i)=c[i];
    }

    printf("\n\n---Below is the reversed array---\n");
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
