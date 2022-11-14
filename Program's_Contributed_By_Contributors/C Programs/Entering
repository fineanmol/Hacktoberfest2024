#include<stdio.h>  
//enter adress of 5 ppl
typedef struct address{
    int houseno;
    int block;
    char city[100];
    char state[100];
}ad;
void printadd(ad add){
    printf("Address is: %d, %d, %s, %s\n",add.houseno,add.block,add.city,add.state );
}
int main(){
    ad adds[5];// similar to struct address add[5]
    printf("Enter info for person 1: ");
    scanf("%d", &adds[0].houseno);
    scanf("%d", &adds[0].block);
    scanf("%s", adds[0].city);
    scanf("%s", adds[0].state);

    printf("Enter info for person 2: ");
    scanf("%d", &adds[1].houseno);
    scanf("%d", &adds[1].block);
    scanf("%s", adds[1].city);
    scanf("%s", adds[1].state);

    printf("Enter info for person 3: ");
    scanf("%d", &adds[2].houseno);
    scanf("%d", &adds[2].block);
    scanf("%s", adds[2].city);
    scanf("%s", adds[2].state);

    printf("Enter info for person 4: ");
    scanf("%d", &adds[3].houseno);
    scanf("%d", &adds[3].block);
    scanf("%s", adds[3].city);
    scanf("%s", adds[3].state);

    printf("Enter info for person 5: ");
    scanf("%d", &adds[4].houseno);
    scanf("%d", &adds[4].block);
    scanf("%s", adds[4].city);
    scanf("%s", adds[4].state);

    printadd(adds[0]);
    printadd(adds[1]);
    printadd(adds[2]);
    printadd(adds[3]);
    printadd(adds[4]);
    return 0;
}
