//Write a Program to print given Matrix in Spiral Form #6339

import java.util.Scanner;

public class SpiralMatrix {
    public static void SpiralMatrix(int matrix[][]){
        int startRow=0;
        int endRow=matrix.length-1;
        int startCol=0;
        int endCol=matrix[0].length-1;
        while(startRow<=endRow && startCol<=endCol){
            //top
            for(int j=startCol;j<=endCol;j++){
                System.out.print(matrix[startRow][j]+" ");
            }

            //right
            for(int i=startRow+1;i<=endRow;i++){
                System.out.print(matrix[i][endCol]+" ");
            }
            //bottom
            for(int j=endCol-1;j>=startCol;j--){
                if(startCol==endCol){
                    break;
                }
                System.out.print(matrix[endRow][j]+" ");
            }
            
            //left
            for(int i=endRow-1;i>=startRow+1;i--){
                if(startRow==endRow){
                    break;
                }
                System.out.print(matrix[i][startCol]+" ");
            }
            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }
        System.out.println();
    }
    public static void main(String args []) { 
    int matrix[][]=new int[4][4];
    int n=matrix.length,m=matrix[0].length;
    System.out.println("Enter the elements of array: ");
    Scanner sc=new Scanner(System.in);
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     matrix[i][j]=sc.nextInt();
    }
}
//output
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     System.out.print(matrix[i][j]+" ");
    }
    System.out.println();
}
SpiralMatrix(matrix);
    }
}
