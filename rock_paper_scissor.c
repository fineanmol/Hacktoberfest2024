#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game();
int genNum(int n){
    srand(time(NULL));
    int a= (rand()%n)+1;
    return a;
}


int main()
{
    char p[20];
    printf("\nPlease share your name : ");
    fgets(p,20,stdin);
    printf("\n\n");
    printf("\t\tWelcome %s",p);
    printf("\n\n");
    printf("Player 1: Computer\n");
    printf("Player 2: You\n");
    printf("\n");
    game();
    return 0;
}

int game(){
    int p1score=0, p2score=0;
    int p1,p2,temp;
    char var[3][8]={"Rock","Scissor","Paper"};
   

    for(int i=0;i<3;i++){

    printf("Press 1 for Rock, 2 for Scissors, 3 for Paper\n");
    scanf("%d",&p2);
    p1=genNum(3);

    printf("Your choice is %s\n",var[p2-1]);
    printf("Computer's choice is %s\n",var[p1-1]);
    printf("\n");

    if(p1==1 && p2==2){
        p1score++;
    }
    else if(p1==1 && p2==3){
        p2score++;
    }
    else if(p1==2 && p2==1){
        p2score++;
    }
    else if(p1==2 && p2==3){
        p1score++;
    }
    else if(p1==3 && p2==1){
        p1score++;
    }
    else if(p1==3 && p2==2){
        p2score++;
    }
    else if(p1==p2 || p2==p1){
    }
    }

    printf("Your score: %d\n",p2score);
    printf("Computer's score: %d\n",p1score);
    printf("\n");
    if(p1score>p2score){
        printf("Oh, Butter Luck Next Time Computer Wins This Match.......");
    }
    else if(p2score>p1score){
        printf("Hurray, You Win!!!!!!");
        
    }
    else if(p1score==p2score){
        printf("Its a Draw!");
    }
    printf("\n");
    printf("\n Wanna play again....\tThen Press 1");
    scanf("\n%d",&temp);
    if(temp){
        return game();
    }
    else{
        return -1;
    }


    return 0;
}
