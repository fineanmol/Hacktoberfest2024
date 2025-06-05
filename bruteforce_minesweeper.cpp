#include <bits/stdc++.h>
using namespace std;

#define max_mine 99
#define max_side 25
#define max_move 526 

int SIDE;
int MINES;

void clear(){
    cout << "\33[2J\033[1;1H";
    system("pause");
}

bool isvalid(int row,int col){
    return (row>=0)&&(row<SIDE)&&(col>=0)&&(col<SIDE);
}

bool ismine(int row,int col,char board[][max_side]){
    return (board[row][col]=='*');
}

void make_move(int *x,int *y){
    while(true)
    {
        cout<<"\nEnter your move: [row] [column] -> ";
        cin>>*x>>*y;
        if ((*x < SIDE) && (*y < SIDE)){
            return;
        }
        else cout << "\t (Wrong Input)";
    }
}

void printboard(char myboard[][max_side]){
    clear();
    cout<<"\n\n\t\t\t    ";
    for(int i=0;i<SIDE;i++)
    {
        if (i>9)
            cout<<i/10<<" ";
        else
            cout<<"  ";
    }

    cout<<"\n\t\t\t    ";

    for(int i=0;i<SIDE;i++)
        cout<<i%10<<" ";

    cout<<"\n\n";

    for(int i=0;i<SIDE;i++)
    {
        cout<<"\t\t\t    ";
        for(int j=0;j<SIDE;j++){
            cout<<myboard[i][j]<<" ";
        }
        cout<<" "<<i;
        cout<<"\n";
    }
    return;
}

int countadjacent(int row,int col,int mines[][2],char realboard[][max_side]){
    int count=0;
    if(isvalid(row-1,col)==true)
    {
        if(ismine(row-1,col,realboard)==true)
            count++;
    }
    if(isvalid(row+1,col)==true)
    {
        if(ismine(row+1,col,realboard)==true)
            count++;
    }
    if(isvalid(row,col+1)==true)
    {
        if(ismine(row,col+1,realboard)==true)
            count++;
    }
    if(isvalid(row,col-1)==true)
    {
        if(ismine(row,col-1,realboard)==true)
            count++;
    }
    if(isvalid(row-1,col-1)==true)
    {
        if(ismine(row-1,col-1,realboard)==true)
            count++;
    }
    if(isvalid(row-1,col+1)==true)
    {
        if(ismine(row-1,col+1,realboard)==true)
            count++;
    }
    if(isvalid(row+1,col-1)==true)
    {
        if(ismine(row+1,col-1,realboard)==true)
            count++;
    }
    if(isvalid(row+1,col+1)==true)
    {
        if(ismine(row+1,col+1,realboard)==true)
            count++;
    }
    return (count);
}

bool playminesuntil(char myboard[][max_side],char realboard[][max_side],int mines[][2],int row,int col,int *moves_left)
{
    if(myboard[row][col]!='-')
        return false;

    int i,j;
    if(realboard[row][col]=='*')
    {
        myboard[row][col]='*';
        for(i=0;i<MINES;i++)
                myboard[mines[i][0]][mines[i][1]]='*';

        printboard(myboard);
        cout<<"\nYou lost!\n";
        return (true);
    }
    else
    {
        int count=countadjacent(row,col,mines,realboard);
        (*moves_left)--; 
        myboard[row][col]= count+'0';
        if(!count)
        {
            if(isvalid(row-1,col)==true)
            {
                if(ismine(row-1,col,realboard)==false)
                    playminesuntil(myboard, realboard, mines, row-1, col, moves_left);
            }
            if (isvalid (row+1, col) == true)
            {
                if (ismine (row+1, col, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row+1, col, moves_left);
            }
            if (isvalid (row, col+1) == true)
            {
                if (ismine (row, col+1, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row, col+1, moves_left);
            }
            if (isvalid (row, col-1) == true)
            {
                if (ismine (row, col-1, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row, col-1, moves_left);
            }
            if (isvalid (row-1, col+1) == true)
            {
                if (ismine (row-1, col+1, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row-1, col+1, moves_left);
            }
            if (isvalid (row-1, col-1) == true)
            {
                if (ismine (row-1, col-1, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row-1, col-1, moves_left);
            }
            if (isvalid (row+1, col+1) == true)
            {
                if (ismine (row+1, col+1, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row+1, col+1, moves_left);
            }
            if (isvalid (row+1, col-1) == true)
            {
                if (ismine (row+1, col-1, realboard) == false)
                    playminesuntil(myboard, realboard, mines, row+1, col-1, moves_left);
            }
        }
        return (false);
    }
}

void placemines(int mines[][2],char realboard[][max_side])  
{
    bool mark[max_side*max_side];

    memset(mark,false,sizeof(mark));

    for(int i=0;i<MINES;){
        int random=rand()%(SIDE*SIDE);
        int x=random/SIDE;
        int y=random%SIDE;

        if(mark[random]==false)
        {
            mines[i][0]=x;
            mines[i][1]=y;

            realboard[mines[i][0]][mines[i][1]]='*';
            mark[random]=true;
            i++;
        }
    }
}

void initialise(char realboard[][max_side],char myboard[][max_side])
{
    srand(time(NULL));

    int i,j;
    for(i=0;i<SIDE;i++)
        for(j=0;j<SIDE;j++)
        {
            myboard[i][j]=realboard[i][j]='-';
        }
    return;
}

void cheatmines (char realboard[][max_side])
{
    cout<<"The mines locations are-\n";
    printboard (realboard);
    return;
}

void replacemine(int row,int col,char board[][max_side])
{
    for(int i=0;i<SIDE;i++)
    {
        for(int j=0;j<SIDE;j++)
        {
            if(board[i][j]!='*')
            {
                board[i][j]='*';
                board[row][col]='-';
                return;
            }
        }
    }
}

void play()
{
    bool gameover=false;

    char realboard[max_side][max_side],myboard[max_side][max_side];

    int moves_left=SIDE*SIDE-MINES;
    int x,y;
    int mines[max_mine][2];

    initialise(realboard,myboard);

    placemines(mines,realboard);

    cheatmines(realboard);
    int currentmoveindex=0;

    while(gameover==false)
    {
        cout<<"Current Status of Board : \n";
        printboard(myboard);
        make_move(&x,&y);

        if(currentmoveindex==0)
        {
            if(ismine(x,y,realboard)==true)
                replacemine(x,y,realboard);
        }

        currentmoveindex++;

        gameover = playminesuntil(myboard,realboard,mines,x,y,&moves_left);

        if((gameover==false)&&(moves_left==0))
        {
            cout<<"\nYou won !\n";
            gameover=true;
        }
    }
}

int Menu(){
    clear();
    cout<<"\n\t\t\tMINESWEEPER";
    cout<<"\n\n\t\tChoose Difficulty Level: ";
    cout<<"\n\n\t\t0.Beginner\n\t\t1.Intermediate\n\t\t2.Advanced";
    cout<<"\n\n\t\tEnter Choice (0-2) : ";
    int choice;
    cin >> choice;
    return choice;
}

void choosedifficulty()
{
    int choice = Menu();
    if(choice==0)
    {
        SIDE=9;
        MINES=10;
    }
    else if(choice==1)
    {
        SIDE=16;
        MINES=40;
    }
    else if(choice==2)
    {
        SIDE=24;
        MINES=99;
    }
    else
        exit(0);
}

int main()
{
    choosedifficulty();
    play();
    return 0;
}
