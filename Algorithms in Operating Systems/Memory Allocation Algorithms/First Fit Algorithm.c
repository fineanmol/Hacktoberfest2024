#include <stdio.h>
#include <stdlib.h>

void main(){
    int size;
    printf("Enter size of Memory: ");
    scanf("%d",&size);
    
    int memo[size];
    for(int x=0; x<size; x++){
        memo[x] = 0;
    }
    
    printf("A: Allocation\tE: Exit\tC: Choices\n");
    char c, choice;
    do{
        scanf("%c",&c);
        printf("Enter choice: ");
        scanf("%c", &choice);
        if(choice == 'A'){
            int a, b;
            printf("Enter memory range allocated: ");
            scanf("%d %d", &a, &b);
            for(int x=a; x<=b; x++){
                memo[x] = 1;
            }
        }
        else if(choice == 'E'){
            printf("Memory allocated!\n");
        }
        else if(choice == 'C'){
            printf("A: Allocation\tE: Exit\tC: Choices\n");
        }
        else{
            printf("\n");
        }
    }while(choice != 'E');
    
    int allo, flag = 0;
    printf("Enter size of memory you want to allocate: ");
    scanf("%d", &allo);
    for(int x=0; x<size; x++){
        int freeMemo = 0;
        if(memo[x] == 0){
            int index = x;
            while(memo[index] == 0){
                freeMemo++;
                index++;
            }
        }
        if(freeMemo >= allo){
            flag = 1;
            printf("Memory allocated from index %d to index %d", x, (x+allo-1));
            break;
        }
    }
    if(flag == 0){
        printf("Memory is not free. No space can be allocated!");
    }
}
