#include<bits/stdc++.h>
using namespace std;

bool isPossible(char c,int row,int col,vector<vector<char>> &board){
        
    for(int i=0;i<9;i++){
        
        if(board[row][i] == c)  return false;
        
        if(board[i][col] == c)  return false;
        
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c)    return false;
    }    
    
    return true;    
    
}
    
    
bool SudokuSolver(vector<vector<char>> &board){
    
    for(int i=0;i<board.size();i++){
        
        for(int j=0;j<board[i].size();j++){
            
            if(board[i][j] == '.'){
                
                for(char c='1';c<='9';c++){
                    
                    if(isPossible(c,i,j,board)){
                        board[i][j]=c;
                        
                        if(SudokuSolver(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true; 
}

int main(){

    //Additional code for input-output
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	vector<vector<char>> board(9,vector<char>(9));
	char ch;


	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			cin>>ch;
			board[i][j] = ch;
		}
	}

	SudokuSolver(board);

	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}