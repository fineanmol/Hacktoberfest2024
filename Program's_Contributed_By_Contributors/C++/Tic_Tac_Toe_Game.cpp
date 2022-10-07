#include<bits/stdc++.h>
using namespace std;
bool winchecker(char arr[3][3])
{
if((arr[0][0]== 'X' && arr[1][1]=='X' && arr[2][2]=='X') || (arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X') || (arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X') || (arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X') || (arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X') || (arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X') || (arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X') || (arr[0][2]=='X' && arr[1][2]=='X' && arr[2][2]=='X') || (arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O') || (arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O') || (arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O') || (arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O') || (arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O') || (arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O') || (arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O') || (arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O'))
    return true;
    else
    return false;
}
void display_board(char arr[3][3])
{
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
 cout<<" "<<arr[i][j]<<" "<<"|";
}
cout<<endl;
}
}

int main()
{
 system("color 3F");
 char arr[3][3],usymbol,csymbol;
 int i,j,counter=0;
 srand(time(0));
for(int i=0;i<3;i++)
{

    for(int j=0;j<3;j++)
    arr[i][j]='-';
}
 int r=rand();
 cout<<"Welcome to TIC TAC TOE GAME!\n";
 display_board(arr);
 cout<<"Choose your symbol(X or O) ";
 cin>>usymbol;
 if(usymbol!='X' && usymbol!='O')
 {
    cout<<"Enter a valid symbol!!\n";
 cin>>usymbol;
 }
 csymbol=(usymbol=='X'?'O':'X');
 int turn=r%2;
 while(counter!=9)
{
if(turn==0)
{
    while(1)
    {
    cout<<"Your chance\n";
    cout<<"Enter the grid no to fill ";
    cin>>i>>j;
    if(arr[i][j]!='-')
        cout<<"invalid move!!Enter again\n";
    else
    {
    arr[i][j]=usymbol;
    display_board(arr);
    if(winchecker(arr))
    {
        cout<<"Congratulations! You Win!!\n";
        return 0;
    }
    turn=1;
    break;
    }
}
}
else
{
    cout<<"computer's turn\n";
while(1)
{
    if(r%9==0 && arr[0][0]=='-')
    {
    arr[0][0]=csymbol;
    break;
    }
    else if(r%9==1 && arr[0][1]=='-')
    {
    arr[0][1]=csymbol;
    break;
}
    else if(r%9==2 && arr[0][2]=='-')
    {
    arr[0][2]=csymbol;
    break;
    }
    else if(r%9==3 && arr[1][0]=='-')
    {
    arr[1][0]=csymbol;
    break;
}
    else if(r%9==4 && arr[1][1]=='-')
    {
    arr[1][1]=csymbol;
    break;
    }
    else if(r%9==5 && arr[1][2]=='-')
    {
    arr[1][2]=csymbol;
    break;
    }
    else if(r%9==6 && arr[2][0]=='-')
    {
    arr[2][0]=csymbol;
    break;
    }
    else if(r%9==7 && arr[2][1]=='-')
    {
    arr[2][1]=csymbol;
    break;
    }
    else if(r%9==8 && arr[2][2]=='-')
    {
    arr[2][2]=csymbol;
    break;
    }
    else
    {
   r=(r+1)%9;
    }
}
display_board(arr);
if(winchecker(arr))
{
cout<<"You Lost!! Better luck next time\n";
return 0;
}
turn=0;
}
counter++;
}
if(counter==9)
cout<<"Draw Match!!Well Played!\n";
return 0;
}