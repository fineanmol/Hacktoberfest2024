#include<bits/stdc++.h>
#include<thread>
#include <unistd.h>
#include <termios.h>
#include<stdlib.h>
#define width 50
#define height 25
using namespace std;
char prevPos='d';
int x=0,y=1;
char turn='d';
int score=0;
vector<pair<int,int>> snakeBody;
int fruitX,fruitY;
int speed=100000;
vector<vector<char>> board(25,vector<char>(50,' '));

void __init__board()
{
    int i=0,j=0;
    for(i=0;i<height;i++)
    {
        board[i][0]='#';
        for(j=1;j<width-1;j++)
        {
            if(i==0 || i==height-1)
            {
                board[i][j]='#';
            }
            else
            {
                board[i][j]=' ';
            }
        }
        board[i][width-1]='#';
    }

}

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}

void displayBoard()
{
    system("clear");
    for(auto i:board)
    {
        cout<<"\t";
        for(auto j:i)
        {
            cout<<j;
        }
        printf("\n");
    }
    printf("\t\t\tYour Score: %d\n",score);
}

void random_fruit_generator(bool flag)
{
    if(flag)
    {
        fruitX=rand()%width;
        fruitY=rand()%height;
        while((board[fruitY][fruitX]=='#')||(board[fruitY][fruitX]=='*'))
        {
            fruitX=rand()%width;
            fruitY=rand()%height;
        }
    }
    board[fruitY][fruitX]='$';
}

void new_fruit(bool flag)
{
    random_fruit_generator(flag);
}

bool check_fruit(int n, int m)
{
    if(board[n][m]=='$')
    {
        score++;
        speed-=1000;
        new_fruit(true);
        return true;
    }
    return false;
}

void make_valid(pair<int,int> &p)
{
    if(p.first<0)
    {
        p.first=height-1;
    }
    else if(p.first>=height)
    {
        p.first=0;
    }
    if(p.second<0)
    {
        p.second=width-1;
    }
    else if(p.second>=width)
    {
        p.second=0;
    }
}

void run()
{
    int time=1;
    int tempx,tempy;
    snakeBody.push_back(make_pair(y,x));
    while(true)
    {
        usleep(speed);
        if(time==50)
        {
            new_fruit(true);
            time=1;
        }
        if(turn=='d')
        {
            if((x+1)==width-1)
            {
                x=0;
            }
            if(check_fruit(y,x+1))
            {
                time=1;
                snakeBody.push_back(make_pair(snakeBody[snakeBody.size()-1].first,snakeBody[snakeBody.size()-1].second-1));
            }
            __init__board();
            new_fruit(false);
            board[snakeBody[0].first][snakeBody[0].second+1]='@';
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=snakeBody.size()-1;i>0;i--)
            {
                snakeBody[i].first=snakeBody[i-1].first;
                snakeBody[i].second=snakeBody[i-1].second;
            }
            x++;
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=1;i<snakeBody.size();i++)
            {
                make_valid(snakeBody[i]);
                board[snakeBody[i].first][snakeBody[i].second]='*';
            }
            displayBoard();
        }
        else if(turn=='s')
        {
            if((y+1)==height-1)
            {
                y=0;
            }
            if(check_fruit(y+1,x))
            {
                time=1;
                snakeBody.push_back(make_pair(snakeBody[snakeBody.size()-1].first-1,snakeBody[snakeBody.size()-1].second));
            }
            __init__board();
            new_fruit(false);
            board[snakeBody[0].first+1][snakeBody[0].second]='@';
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=snakeBody.size()-1;i>0;i--)
            {
                snakeBody[i].first=snakeBody[i-1].first;
                snakeBody[i].second=snakeBody[i-1].second;
            }
            y++;
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=1;i<snakeBody.size();i++)
            {
                make_valid(snakeBody[i]);
                board[snakeBody[i].first][snakeBody[i].second]='*';
            }
            displayBoard();
        }
        else if(turn=='w')
        {
            if((y-1)==0)
            {
                y=height-1;
            }
            if(check_fruit(y-1,x))
            {
                time=1;
                snakeBody.push_back(make_pair(snakeBody[snakeBody.size()-1].first+1,snakeBody[snakeBody.size()-1].second));
            }
            __init__board();
            new_fruit(false);
            board[snakeBody[0].first-1][snakeBody[0].second]='@';
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=snakeBody.size()-1;i>0;i--)
            {
                snakeBody[i].first=snakeBody[i-1].first;
                snakeBody[i].second=snakeBody[i-1].second;
            }
            y--;
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=1;i<snakeBody.size();i++)
            {
                make_valid(snakeBody[i]);
                board[snakeBody[i].first][snakeBody[i].second]='*';
            }
            displayBoard();
        }
        else if(turn=='a')
        {
            if((x-1)==0)
            {
                x=width-1;
            }
            if(check_fruit(y,x-1))
            {
                time=1;
                snakeBody.push_back(make_pair(snakeBody[snakeBody.size()-1].first,snakeBody[snakeBody.size()-1].second+1));
            }
            __init__board();
            new_fruit(false);
            board[snakeBody[0].first][snakeBody[0].second-1]='@';
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=snakeBody.size()-1;i>0;i--)
            {
                snakeBody[i].first=snakeBody[i-1].first;
                snakeBody[i].second=snakeBody[i-1].second;
            }
            x--;
            snakeBody[0].first=y;
            snakeBody[0].second=x;
            for(int i=1;i<snakeBody.size();i++)
            {
                make_valid(snakeBody[i]);
                board[snakeBody[i].first][snakeBody[i].second]='*';
            }
            displayBoard();
        }
        time++;
    }
}
thread snake(run);

void direction(char dt)
{
    if(dt!=prevPos)
    {
        if(!(dt=='a' && prevPos=='d') && !(dt=='d' && prevPos=='a'))
        {
            if(!(dt=='w' && prevPos=='s') && !(dt=='s' && prevPos=='w'))
            {
                turn=dt;
                prevPos=dt;
            }
        }
    }
}

void controll_buttons()
{
    char button;
    for(;;)
    {
        button=getch();
        if(button=='q')
        {
            exit(0);
        }
        direction(button);
    }
}
thread controll(controll_buttons);

int main()
{
    __init__board();
    random_fruit_generator(true);
    cout<<"Welcome to the Snake game"<<endl;
    controll.join();
    snake.join();
    return 0;
}