//This code is optmizied according to time complexity
#include<bits/stdc++.h>
using namespace std;

void printSolution(int col,vector<string> &board,int n,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal){

	if(col == n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		return;
	}


	for(int row=0;row<n;row++){

		if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[(n-1)+(col-row)] == 0){

			board[row][col] = 'Q';
			leftRow[row] = 1;
			lowerDiagonal[row+col] = 1;
			upperDiagonal[(n-1)+(col-row)] = 1;
			printSolution(col+1,board,n,leftRow,lowerDiagonal,upperDiagonal);
			board[row][col] = '.';
			leftRow[row] = 0;
			lowerDiagonal[row+col] = 0;
			upperDiagonal[(n-1)+(col-row)] = 0; 
		}
	}
}


int main(){

	//Additonal code for input-output
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	int n;
	cin>>n;

	vector<string> board(n);
	string s(n,'.');

	for(int i=0;i<n;i++)
		board[i] = s;

	vector<int> leftRow(n,0),lowerDiagonal(2*n-1,0),upperDiagonal(2*n-1,0);

	printSolution(0,board,n,leftRow,lowerDiagonal,upperDiagonal);


	return 0;
}