//This is the least optimized approach
#include<bits/stdc++.h>
using namespace std;


bool isSafe(int row,int col,int n,vector<string> &board){

	int tempRow = row;
	int tempCol = col;

	while(row>=0 && col>=0){

		if(board[row][col] == 'Q')	return false;
		row--;
		col--;
	}

	row = tempRow;
	col = tempCol;

	while(col >= 0){

		if(board[row][col] == 'Q')	return false;
		col--;
	}

	row = tempRow;
	col = tempCol;

	while(row < n && col >= 0){

		if(board[row][col] == 'Q')	return false;
		row++;
		col--;
	}


	return true;
}

void printAns(int col,int n,vector<string> &board){

	if(col == n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}

	for(int row=0;row<n;row++){

		if(isSafe(row,col,n,board)){
			board[row][col] = 'Q';
			printAns(col+1,n,board);
			board[row][col] = '.';
		}
	}

}


int main(){

	//Additional code for input and output
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

	printAns(0,n,board);



	return 0;
}