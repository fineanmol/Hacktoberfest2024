#include<iostream>
#include<math.h>
using namespace std;

bool canPlace(int grid[][9], int n, int i, int j, int d){
	for(int k=0; k<n; k++) {   
		if(grid[i][k] == d or grid[k][j] == d) { // to check in same row or same col
			return false;
		}
	}
	int rn= sqrt(n);
	int sx=i-(i%rn);
	int sy=j-(j%rn);
	for(int x=sx; x<sx+rn; x++) {
		for(int y=sy; y<sy+rn; y++) {
			if(grid[x][y] == d) {  // to check sub grid
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(int grid[][9], int n ,int i,int j){
	//base case
	if(i==n){
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	if(j==n){
		// all the comluns are assigned so we move to next row
		solveSudoku(grid,n,i+1,0);
		return;
	}
	if(grid[i][j]!=0){
		// (i,j)th cell not empty therefore skip it
		solveSudoku(grid,n,i,j+1);
		return;
	}
	// (i, j)th cell is an empty therefore we have to
	// assign it a digit 'd'
	for(int d=1;d<=9;d++)
	{
		if(canPlace(grid,n,i,j,d)){
			grid[i][j]=d;
			solveSudoku(grid,n,i,j+1);
			grid[i][j]=0; // back tracking if filling is wrong
		}
	}
}

int main(){
	int n = 9;

	int grid[][9] = {{7, 8, 0, 4, 0, 0, 1, 2, 0}, 
			         {6, 0, 0, 0, 7, 5, 0, 0, 9}, 
			         {0, 0, 0, 6, 0, 1, 0, 7, 8}, 
			         {0, 0, 7, 0, 4, 0, 2, 6, 0}, 
			         {0, 0, 1, 0, 5, 0, 9, 3, 0}, 
			         {9, 0, 4, 0, 6, 0, 0, 0, 5}, 
			         {0, 7, 0, 3, 0, 0, 0, 1, 2}, 
			         {1, 2, 0, 0, 0, 7, 4, 0, 0}, 
			         {0, 4, 9, 2, 0, 6, 0, 0, 7}};

	solveSudoku(grid,n,0,0);	
	return 0;
}