bool isValidSudoku(vector<vector<char>>& board) {
  bool hor[9][9] = {0}, ver[9][9] = {0}, sqr[9][9] = {0};
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      char c = board[i][j];
      if(c != '.') {
        if(hor[i][c % 9]++) return false;
        if(ver[j][c % 9]++) return false;
        if(sqr[(i / 3) * 3 + j / 3][c % 9]++) return false;
      }
    }
  }
  return true;
}
