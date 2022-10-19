#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    //Enter the number of row and col in the matrix

    cin>>row>>col;
    int A[row][col];
    
    //Inserting th value in the matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>A[i][j];
        }
    }
    vector<int> ds;

    //set four pointer and a direction index

    int top=0,bottom=row-1,left=0,right=col-1;
    int dir=0;
    while(top<=bottom && left<=right)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++){ds.push_back(A[top][i]);}
            top++;
        }
        else if(dir==1)
        {
            for(int i=top;i<=bottom;i++){ds.push_back(A[i][right]);}
            right--;
        }
        else if(dir==2)
        {
            for(int i=right;i>=left;i--){ds.push_back(A[bottom][i]);}
            bottom--;
        }
        else if(dir==3)
        {
            for(int i=bottom;i>=top;i--){ds.push_back(A[i][left]);}
            left++;
        }
        dir=(dir+1)%4;
    }
    for(auto it:ds)
    {
        cout<<it<<" ";
    }
}
