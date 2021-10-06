// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
     bool valid(int grid[N][N] , int i ,int j , int item){
        for(int x=0;x<9;x++){
            if(grid[i][x] == item){
                return false;
            }
        }
        for(int y=0;y<9;y++){
            if(grid[y][j] == item){
                return false;
            }
        }
        int smi = i/3 * 3;
        int smj = j/3 * 3;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(grid[smi+x][smj+y] == item){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(int grid[N][N],int i,int j){
        if(i == 9){
            printGrid(grid);
            return;
        }
        int ni = 0;
        int nj = 0;
        if(j == 9-1){
            ni = i+1;
             nj = 0;
        }else{
            ni = i;
            nj = j+1;
        }
        if(grid[i][j] != 0){
            solve(grid,ni,nj);
        }
        else{
            for(int x=1;x<=9;x++){
                if(valid(grid,i,j,x)){
                    grid[i][j] = x;
                    solve(grid,ni,nj);
                    grid[i][j] = 0;
                }
            }
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        
        int i=0,j=0;
        if(solve(grid,i,j)){
            return true;
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                cout<<grid[x][y]<<" ";
                }
                cout<<endl;
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
