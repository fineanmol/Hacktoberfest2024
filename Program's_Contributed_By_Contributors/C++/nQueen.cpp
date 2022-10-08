/*
Name : Rounak Ghosh
Username : Rounak-Ghosh
About : 4th year undergrad student at GCETTB
*/

#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n)
{
    int row, col;
    for(row=0; row<x; row++)    // column check 
    {
        if(arr[row][y] == 1)
            return false;
    }

    row = x;
    col = y;
    while(row >= 0 && col >= 0)       // left upper diagonal
    {
        if(arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = x;
    col = y;
    while(row >= 0 && col <= n)       // right upper diagonal
    {
        if(arr[row][col] == 1)
            return false;
        row--;
        col++;
    }    

    return true;
}

bool nQueen(int** arr, int x, int n)        // y is not included cuz we aren't gonna check that row, cuz already a queen is placed
{
    if(x >= n)
        return true;
    
    for(int col=0; col<n; col++)
    {
        if(isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if(nQueen(arr,x+1,n))
                return true;
        }    
        arr[x][col] = 0;    // backtracking
    }
    
    return false;
}

int main()          // Program working perfectly in online compiler, but not here lol
{
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++)
        arr[i] = new int[n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            arr[i][j]=0;

    if(nQueen(arr, 0, n))
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }          

    return 0;
}