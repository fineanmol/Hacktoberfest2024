public class backtracking_sudukoSolver {
    
    public static char board[][] = {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

    public static void PrintSuduko(char[][] board){
        for(int row=0;row<board.length;row++){
            for(int column = 0;column<board.length;column++){
                System.out.print(board[row][column]+" ");
            }
            System.out.println();
        }
    }
    public static boolean isSafe(char board[][], int row, int column, int value){
        //horizontal and vertical check
        for(int i=0;i<board.length;i++){
            if(board[row][i] == (char)(value +'0')){
                return false;
            }
            if(board[i][column] == (char)(value +'0')){
                return false;
            }
        }

        //grid 3*3 matrix
        int matrix_start_row = (row/3)*3;
        int matrix_start_column = (column/3)*3;
        //in a small 3*3 matrix
        for(int i= matrix_start_row; i< matrix_start_row+3;i++){
            for(int j=matrix_start_column;j<matrix_start_column +3;j++){
                if(board[i][j]==(char) (value+'0')){
                    return false;
                }
            }
        }

        return true;

    }
    public static boolean SudukoSolver(char board[][], int row, int column){
        if(row == board.length){
            return true;
        }
        
        int nrow;
        if(column==board.length-1){
            nrow = row+1;
            column = 0;

        }else{
            nrow = row;
            column+=1;
        }
        if(board[row][column]!='.'){
            if(SudukoSolver(board, nrow, column)){
            return true;
            }
        }
        else{
            for(int i=1;i<=9;i++){
                if(isSafe(board, row, column , i)){
                    board[row][column] = (char)(i+'0');
                    if(SudukoSolver(board, nrow, column)){
                        return true;
                    }
                    else{
                        board[row][column] ='.';
                    }
                }
            }
        }

        return false;
    }
    public static void main(String[] args) {
        // System.out.println("backtracking_sudukoSolver");
        PrintSuduko(board);
        System.out.println();
        SudukoSolver(board, 0, 0);
        PrintSuduko(board);
    }
}
