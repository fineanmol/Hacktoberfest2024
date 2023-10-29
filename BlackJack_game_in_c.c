#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(0));
    int choice,sum=0,sum1=0;
    int number_1[30],number_2[30];
    for(int i=0;i<30;i++){
        number_1[i]=(rand()%10)+1;
        number_2[i]=(rand()%10)+1;
    }
    int dealer[10],player[10];
   for(int i=0;i<10;i++){
    dealer[i]=number_1[i];
    player[i]=number_2[i];
   }

   sum =(player[0]+player[1]);
   sum1=dealer[0]+dealer[1];
    printf("Your Cards are [%d %d] Sum = %d\n",player[0],player[1],sum);
    printf("Dealer's Cards are [x %d] Sum = %d\n",dealer[1],dealer[1]);
      int q=2,t=1;
    while(1){
        printf("press 0 for Hit\n");
        printf("press 1 to Stand\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 0:
         printf("Your next card is %d ",player[q]);
        sum+=player[q];
        q++;
        printf("Sum =%d\n",sum);
        if(sum>21){
            printf("You lose\n");
            exit(0);
        }
        else if(sum==21){
            printf("You win\n");
            exit(0);
        }
        else if(sum<21){
            continue;
        }

            break;


        case 1:
        while(sum1<21){
         printf("Dealer's next card is %d ",dealer[t+1]);
         sum1 +=dealer[t+1];
         t++;
         printf("Sum =%d\n",sum1);

         if(sum1==21){
            printf("You lose\n");
            exit(0);
         }
         else if(sum1>21){
            printf("You win\n");
            exit(0);
        }
        else if(sum1==sum){
            printf("Draw\n");
            exit(0);
        }
        else if(sum1>sum){
            printf("You lose\n");
            exit(0);
        }
        else if(sum1<sum){
            continue;
        }

        }
            break;
        default:
        printf("Enter the valid number\n");
            break;
        }
    }
}
