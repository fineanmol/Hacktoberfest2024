/* Accept 2 arrays as input and performing various operations on them */
/* Java Program */ 

import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String args[]) {
    // initializing
    int row, col, i, j;
    i=0;
    j=0;
    boolean uppertriangular = true;
    int mat1[][] = new int[3][3];
    int mat2[][] = new int[3][3];
    int mat3[][] = new int[3][3];
    
    
    Scanner scan = new Scanner(System.in);

    // enter row and column 
    System.out.print("Enter number of rows: ");
    row = scan.nextInt();
    System.out.print("Enter number of columns: ");
    col = scan.nextInt();

    // enter matrix elements
    System.out.println("Enter for first matrix "  );
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        mat1[i][j] = scan.nextInt();
      }
    }
     System.out.println("Enter for second matrix " );
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        mat2[i][j] = scan.nextInt();
      }
    }

    // the matrix is here.
    System.out.print("The matrix1 is :\n");
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        System.out.print(mat1[i][j] + "  ");
      }
      System.out.println();
    }
    System.out.print("The matrix2 is :\n");
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        System.out.print(mat2[i][j] + "  ");
      }
      System.out.println();
    }
     int choice;
     
     do {
         
      System.out.println("Choose the matrix operation ");
      System.out.println("1. Check if square matrix");
      System.out.println("2. Check if upper triangular matrix");
      System.out.println("3. Transpose");
      System.out.println("4. Addition");
      System.out.println("5. Multiplication");
      System.out.println("6. Exit");
      System.out.print("Enter your choice: ");
      choice = scan.nextInt();
      
      switch(choice) {
          
          case 1 :
              mat3 = squarematrix(mat1);
              if (row==col) 
                  System.out.println("matrix is a square matrix");
              
              System.out.println(Arrays.deepToString(mat3));
              
         break;
          case 2 :
              mat3 = uppertriangular(mat1);
              for ( i = 0; i < row; i++) {
            for ( j = 0; j < i; j++) {
                if (mat1[i][j] != 0) {
                    uppertriangular = false;
                    break;
                }
            }
            if (!uppertriangular) {
                break;
            }
        }

    
            if (uppertriangular) 
            System.out.println("Upper triangular matrix.");
         
        else 
            System.out.println("Not an Upper triangular matrix.");
                
                System.out.println(Arrays.deepToString(mat3));
              
         break;
           case 3 :
              mat3 = transpose(mat1);
              System.out.println("Transpose of the first matrix: ");
              System.out.println(Arrays.deepToString(mat3));
         break;
           case 4 :
               mat3 = add(mat1, mat2);
               System.out.println("Sum of matrix: ");
               System.out.println(Arrays.deepToString(mat3));
         break;
           case 5 :
               mat3 = multiply(mat1, mat2);
               System.out.println("Multiplication of matrix: ");
               System.out.println(Arrays.deepToString(mat3));
         break;
           case 6 :
                System.out.println("Thank You.");
         return;
           default:
                System.out.println("Invalid input.");
                System.out.println("Please enter the correct input.");
      }
    } while (true);
    
  }
  
  
  public static int[][] squarematrix (int[][] mat1) { 
       
        int row, col;
        row = 0;
        col = 0;
        
              if (row==col) 
                  System.out.println("matrix is a square matrix");
      return mat1;
    }
              
   public static int[][] uppertriangular (int[][] mat1)  {
       int row;
       row = 0;
       boolean uppertriangular = true;
       for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                if (mat1[i][j] != 0) {
                    uppertriangular = false;
                    break;
                }
            }
            if (!uppertriangular) {
                break;
            }
        }

    
            if (uppertriangular) 
            System.out.println("Upper triangular matrix.");
         
        else 
            System.out.println("Not an Upper triangular matrix.");
            return mat1;
        
}
    public static int[][] transpose(int[][] mat1) {

    
    int row = mat1.length;
    int col = mat1[0].length;

    
    int temp[][] = new int[row][col];

    
    for (int i = 0; i < row; i++) {
      
      for (int j = 0; j < col; j++) {
        
        temp[i][j] = mat1[j][i];
      }
    }

    
    return temp;
  } 
  public static int[][] add(int[][] mat1, int[][] mat2) {

    
    int row = mat1.length;
    int col = mat2[0].length;

    
    int sum[][] = new int[row][col];
 for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        sum[i][j] = mat1[i][j] + mat2[i][j];
      }
    }

    
    return sum;
  }
   public static int[][] multiply(int[][] mat1, int[][] mat2) {


    int row = mat1.length;
    
    int col = mat2[0].length;

    
    int product[][] = new int[row][col];

    
    for (int i = 0; i < row; i++) {
      
      for (int j = 0; j < col; j++) {
        
        product[i][j] = 0;

        
        for (int k = 0; k < mat1[0].length; k++) {
          product[i][j] += mat1[i][k] * mat2[k][j];
        }
      }
    }
    return product;
  }

  
  
}
