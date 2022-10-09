#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 8

//Function to check whether the current indexes lie inside the chessboard
//and has been encountered for the first time in a particular tour
int validIndex(int x, int y, int board[n][n]){
    return (x>=0 && x<n && y>=0 && y<n && (board[x][y]==-1));
}

//Recursive Backtracking function to solve The Knight's Tour problem
int backtrackingSol(int x, int y, int moveNum, int board[n][n], int xmove[8], int ymove[8]){
    int next_x, next_y;         //next indexes after a move

    if(moveNum == n*n){        //if the knight has visited each square exactly once => return 1    
        return 1;
    }
 
    for(int i=0; i<8; i++) {            //trying all the next moves from the cuurent location
        next_x = x+xmove[i];
        next_y = y+ymove[i];
        if (validIndex(next_x, next_y, board)) {
            board[next_x][next_y] = moveNum;
            if (backtrackingSol(next_x, next_y, moveNum+1, board, xmove, ymove) == 1){
                return 1;
            }
            else{
                board[next_x][next_y] = -1;             //if tour is not possible then set the square as
            }                                           //unvisited and move to the next move from the beginning
        }
    }
    return 0;
}

int main(){

    int board[n][n];            //chess board
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            board[i][j] = -1;           //all the unvisited squares hold value -1
        }
    }

    board[0][0] = 0;            //knight is initially at first square

    //xmove and ymove define all the possible move combinations of the knight
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
    //calling the backtracking function to check if any tour was possible 
    //and printing the tour if it was possible
    if (backtrackingSol(0, 0, 1, board, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    }
    else{
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++){
                cout <<board[i][j]<<"  ";
            }
            cout<<"\n";
        }
    }
    return 0;
}

/*Output:
0  59  38  33  30  17  8  63  
37  34  31  60  9  62  29  16  
58  1  36  39  32  27  18  7  
35  48  41  26  61  10  15  28  
42  57  2  49  40  23  6  19  
47  50  45  54  25  20  11  14  
56  43  52  3  22  13  24  5  
51  46  55  44  53  4  21  12 
*/