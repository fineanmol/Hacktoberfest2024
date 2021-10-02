import java.util.Scanner;
public class NQueens 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n=sc.nextInt();
        char chessBoard[][]=new char[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                chessBoard[i][j]='-';
        if(solveNQueens(chessBoard,0,n)) solution(chessBoard,n);
        else System.out.println("No solution exists");
    }
    public static void solution(char chessBoard[][], int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                System.out.print(" "+chessBoard[i][j]+" ");
            System.out.println();
        }
    }
    public static boolean isSafe(char chessBoard[][], int row, int column, int n)
    {
        int i,j;
        for(i=0;i<column;i++)
        {
            if(chessBoard[row][i]=='Q') return false;
        }
        for(i=row,j=column; i>=0 && j>=0;i--,j--)
        {
            if(chessBoard[i][j]=='Q') return false;
        }
        for(i=row,j=column; i<n && j>=0;i++,j--)
        {
            if(chessBoard[i][j]=='Q') return false;
        }
        return true;
    }
    public static boolean solveNQueens(char chessBoard[][], int column, int n)
    {
        if(column>=n) return true;
        for(int i=0;i<n;i++)
        {
            if(isSafe(chessBoard,i,column,n))
            {
                chessBoard[i][column]='Q';
                if(solveNQueens(chessBoard, column+1,n)) return true;
                chessBoard[i][column]='-';
            }
        }
        return false;
    }
}
