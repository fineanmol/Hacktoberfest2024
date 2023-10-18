#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
char pst[9] = {'1','2','3','4','5','6','7','8','9'};
void board()
{
    system("cls");
    printf("---------------------Tic Tac Toe--------------------\n\n");
    printf("Player 1(x)-----------------Player 2(o)\n\n");
    // printf("   |   |   \n");
    printf(" %c | %c | %c \n",pst[0],pst[1],pst[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",pst[3],pst[4],pst[5]);
    printf("___|___|___\n");
    // printf("   |   |   \n");
    printf(" %c | %c | %c \n",pst[6],pst[7],pst[8]);
    printf("   |   |   \n");

}
int checkwin()
{
    if(pst[0]==pst[1] && pst[1] == pst[2])
    return 1;
    else if(pst[3]==pst[4] && pst[4] ==pst[5])
    return 1;
    else if(pst[6]==pst[7] && pst[7] == pst[8])
    return 1;
    else if(pst[0]==pst[3] && pst[3] == pst[6])
    return 1;
    else if(pst[1]==pst[4] && pst[4] == pst[7])
    return 1;
    else if(pst[2]==pst[5] && pst[5] == pst[8])
    return 1;
    else if(pst[0]==pst[4] && pst[4] == pst[8])
    return 1;
    else if(pst[2]==pst[4] && pst[4] == pst[6])
    return 1;
    else if (pst[0] != '1' && pst[1] != '2' && pst[2] != '3' && pst[3]!= '4' && pst[4]!='5' && pst[5]!='6' && pst[6]!='7' && pst[7]!='8' && pst[8]!= '9' )
    return 0;
    else 
    return -1;
}
void main()
{
    char mark,name1[20],name2[20],name[20];
    printf("Enter name for player no.1 : ");
    gets(name1);
    printf("Enter name for player no.2 : ");
    fflush(stdin);
    gets(name2);
    board();
    int player = 1,d,i;
    do{
        player = (player%2)? 1:2;
        mark = (player%2)? 'x':'o';
        if(player == 1)
        printf("%s's turn\n",name1);
        else
        printf("%s's turn\n",name2);
        printf("Enter the position number : ");
        scanf("%d",&d);
        if(d==1 && pst[d-1] == '1') 
        pst[d-1]=mark;
        else if(d==2 && pst[d-1] == '2') 
        pst[d-1]=mark;
        else if(d==3 && pst[d-1] == '3') 
        pst[d-1]=mark;
        else if(d==4 && pst[d-1] == '4') 
        pst[d-1]=mark;
        else if(d==5 && pst[d-1] == '5') 
        pst[d-1]=mark;
        else if(d==6 && pst[d-1] == '6') 
        pst[d-1]=mark;
        else if(d==7 && pst[d-1] == '7') 
        pst[d-1]=mark;
        else if(d==8 && pst[d-1] == '8') 
        pst[d-1]=mark;
        else if(d==9 && pst[d-1] == '9') 
        pst[d-1]=mark;
        else
        {printf("Invalid move");player--;}
        board();
        i = checkwin();
        player++;

    }while(i==-1);
    board();
    if(i==1)
    {
        if(player == 1)
        printf("%s won the game",name2);
        else
        printf("%s won the game",name1);
    }
    else
    printf("The result is draw ");
    printf("\nPress any to exit");
    getch();

}