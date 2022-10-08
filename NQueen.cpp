#include <bits/stdc++.h>
#define int long long 
using namespace std;
bool canPlace(int board[][20],int n,int x,int y)
{
    //column check
    for(int k=0;k<x;k++)
    {
        if(board[k][y]==1)
        return false;

    }
    //left_diagonal
    int i=x;
    int j=y;
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
        return false;
        i--;
        j--;

    }
    //right_diagonal
    i=x;
    j=y;
    while(i>=0 && j<n)
    {
        if(board[i][j]==1)
        return false;
        i--;
        j++;


    }
    return true;

}
void print_board(int n,int board[][20])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;

    }
}
bool solveNqueen(int n,int board[][20],int i)
{
//base_case
if(i==n)
{
    print_board(n,board);
    return true;

}
//recursive_case
//try to place a queen in every row
for(int j=0;j<n;j++)
{
    //whether the current i,j location is safe or not
    if(canPlace(board,n,i,j))
    {
        board[i][j]=1;;
        bool success=solveNqueen(n,board,i+1);
        if(success)
        return true;
        //backtrack
        board[i][j]=0;

    }
}
return false;//return false when we have checked each column for the particular row (configuration)

}
int32_t main()
{

int board[20][20]={0};
int n;
cin>>n;
solveNqueen(n,board,0);


    return 0;
}
