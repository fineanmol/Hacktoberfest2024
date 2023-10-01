#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isSafe(vector<vector<int>>&board,int row, int col, int n)
    {
        for(int i=0;i<col;i++)
        {
            if(board[row][i]==1)
              return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]==1)
              return false;
        }
        for(int i=row,j=col;i<n && j>=0;i++,j--)
        {
            if(board[i][j]==1)
              return false;
        }
        return true;
    }
    void boardSolve(vector<vector<int>>&board, int col, int n, int &count)
    {
        int i;
        if(col>=n)
        {
            count+=1;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col,n))
            {
                board[i][col]=1;
                boardSolve(board,col+1,n,count);
                board[i][col]=0;
            }
        }
    }
    int totalNQueens(int n) 
    {
        vector<int>temp(n,0);
        vector<vector<int>>board(n,temp);
        int count=0;
        boardSolve(board,0,n,count);
        return count;
        
    }
    int main()
    {
        return totalNQueens(4);
    }
};
