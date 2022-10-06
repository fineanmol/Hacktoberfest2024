#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solve(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solve(board))
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
int main() {
    vector<vector<char>>board{
        {'3', '.', '.', '8', '.', '1', '.', '.', '2'},
        {'2', '.', '1', '.', '3', '.', '6', '.', '4'},
        {'.', '.', '.', '2', '.', '4', '.', '.', '.'},
        {'8', '.', '9', '.', '.', '.', '1', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '.', '5', '.'},
        {'7', '.', '2', '.', '.', '.', '4', '.', '9'},
        {'.', '.', '.', '5', '.', '9', '.', '.', '.'},
        {'9', '.', '4', '.', '8', '.', '7', '.', '5'},
        {'6', '.', '.', '1', '.', '7', '.', '.', '3'}
    };
   
    solve(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<"|";
            cout<<"\n";
    }
    return 0;
}