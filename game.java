
public class game
{
	
		
  private static final int GRID_SIZE = 9;
  
  public static void main(String[] args) {
    
    int[][] board = {
        {7, 0, 2,  0, 5, 0,  6, 0, 0},
        {0, 0, 0,  0, 0, 3,  0, 0, 0},
        {1, 0, 0,  0, 0, 9,  5, 0, 0},

        {8, 0, 0,  0, 0, 0,  0, 9, 0},
        {0, 4, 3,  0, 0, 0,  7, 5, 0},
        {0, 9, 0,  0, 0, 0,  0, 0, 8},
        
        {0, 0, 9,  7, 0, 0,  0, 0, 5},
        {0, 0, 0,  2, 0, 0,  0, 0, 0},
        {0, 0, 7,  0, 4, 0,  2, 0, 3} 
      };
    
    printBoard(board);
    
    if (solveBoard(board)) {
      System.out.println("Solved successfully!");
    }
    else {
      System.out.println("Unsolvable board :(");
    }
    
    printBoard(board);
    
  }
  
  
  private static void printBoard(int[][] board) {

    System.out.println("-----------");

    for (int row = 0; row < GRID_SIZE; row++) {
      if (row % 3 == 0 && row != 0) {
        System.out.println("-----------");
      }
      for (int column = 0; column < GRID_SIZE; column++) {
        if (column % 3 == 0 && column != 0) {
          System.out.print("|");
        }
        System.out.print(board[row][column]);
      }
      System.out.println();
    }

    System.out.println("-----------");

  }


  private static boolean isNumberInRow(int[][] board, int number, int row) {
    for (int i = 0; i < GRID_SIZE; i++) {
      if (board[row][i] == number) {
        return true;
      }
    }
    return false;
  }
  
  private static boolean isNumberInColumn(int[][] board, int number, int column) {
    for (int i = 0; i < GRID_SIZE; i++) {
      if (board[i][column] == number) {
        return true;
      }
    }
    return false;
  }
  
  private static boolean isNumberInBox(int[][] board, int number, int row, int column) {
    int localBoxRow = row - row % 3;
    int localBoxColumn = column - column % 3;
    
    for (int i = localBoxRow; i < localBoxRow + 3; i++) {
      for (int j = localBoxColumn; j < localBoxColumn + 3; j++) {
        if (board[i][j] == number) {
          return true;
        }
      }
    }
    return false;
  }
  
  private static boolean isValidPlacement(int[][] board, int number, int row, int column) {
    return !isNumberInRow(board, number, row) &&
        !isNumberInColumn(board, number, column) &&
        !isNumberInBox(board, number, row, column);
  }
  
  private static boolean solveBoard(int[][] board) {
    for (int row = 0; row < GRID_SIZE; row++) {
      for (int column = 0; column < GRID_SIZE; column++) {
        if (board[row][column] == 0) {
          for (int numberToTry = 1; numberToTry <= GRID_SIZE; numberToTry++) {
            if (isValidPlacement(board, numberToTry, row, column)) {
              board[row][column] = numberToTry;
              
              if (solveBoard(board)) {
                return true;
              }
              else {
                board[row][column] = 0;
              }
            }
          }
          return false;
        }
      }
    }
    return true;
  
  
  }
  }
