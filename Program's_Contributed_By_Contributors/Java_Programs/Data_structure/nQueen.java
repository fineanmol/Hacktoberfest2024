//N-Queens with Normal Array and Inputs

import java.util.Scanner;
public class nQueen {

  public static void display(int[][] mat,int N) {
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        System.out.print(mat[i][j]+", ");
      }
      System.out.println();
    }
    System.out.println("GAP");
  }
  
  public static int issafe(int[][] mat,int row,int col,int N) {
    int i,j;
    for(j=col;j>=0;j--) {
      if(mat[row][j]==1) {
        return 0;
      }
    }
    
    for(i=row,j=col;i>=0&&j>=0;i--,j--) {
      if(mat[i][j]==1) {
        return 0;
      }
    }
    for(i=row,j=col;i<N-1&&j>=0;i++,j--) {
      if(mat[i][j]==1) {
        return 0;
      }
    }
    return 1;
  }
  
  public static void solve(int[][] mat,int col,int N) {
    
    if(col==N) {
      display(mat,N);
    }else {
      int row=0;
      for(row=0;row<N;row++) {
        if(issafe(mat,row,col,N)==1) {
          mat[row][col]=1;
          solve(mat,col+1,N);
          mat[row][col]=0;
        }
      }
    }
  }
  
  public static void main(String [] args) {
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    int[][] mat=new int[N][N];
    solve(mat,0,N);
    sc.close();
  }
  
}
//Contributed By Ashutosh Ray
