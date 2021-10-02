//coded by shreeyachatzz
import java.util.Scanner;//For importing Scanner Class
class MatrixMultiplication
{
   public static void main(String args[])
   {
      int m, n, p, q, sum = 0, c, d, k;
      //To accept the no of rows and columns from the user for bothe the matices and then to accept elements of the matrix
      Scanner in = new Scanner(System.in);
      System.out.println("Enter the number of rows and columns of first matrix");
      m = in.nextInt();
      n = in.nextInt();
 
      int first[][] = new int[m][n];
 
      System.out.println("Enter elements of first matrix");
 
      for (c = 0; c < m; c++)
      {
         for (d = 0; d < n; d++)
        { 
            first[c][d] = in.nextInt();
        }
    }
      System.out.println("Enter the number of rows and columns of second matrix");
      p = in.nextInt();
      q = in.nextInt();
      //To multiply matrices as the elements of the next matrix are accepted by user
      if (n != p)
         System.out.println("The matrices can't be multiplied with each other.");
      else
      {
         int second[][] = new int[p][q];
         int multiply[][] = new int[m][q];
 
         System.out.println("Enter elements of second matrix");
 
         for (c = 0; c < p; c++)
         {
            for (d = 0; d < q; d++)
            {
               second[c][d] = in.nextInt();
            }
         }
 
         for (c = 0; c < m; c++)
         {
            for (d = 0; d < q; d++)
            {  
               for (k = 0; k < p; k++)
               {
                  sum = sum + first[c][k]*second[k][d];
               }
 
               multiply[c][d] = sum;
               sum = 0;
            }
         } 
         System.out.println("The First Matrix: ");
             for (c = 0; c < m; c++)
         {
            for (d = 0; d < n; d++)
            {
               System.out.print(first[c][d]+"\t");
            }
 
            System.out.print("\n");
          }
          System.out.println("The Second Matrix: ");
          for (c = 0; c < p; c++)
         {
            for (d = 0; d < q; d++)
            {
               System.out.print(second[c][d]+"\t");
            }
 
            System.out.print("\n");
         }
         System.out.println("Product of the matrices:");
 
         for (c = 0; c < m; c++)
         {
            for (d = 0; d < q; d++)
            {
               System.out.print(multiply[c][d]+"\t");
            }
 
            System.out.print("\n");
         }
      }
    }
 }
/*
 *INPUT
  Enter the number of rows and columns of first matrix
  2
  3
  Enter elements of first matrix
  3
  4
  5
  6
  7
  8
  Enter the number of rows and columns of second matrix
  3
  2
  Enter elements of second matrix
  3
  4
  5
  6
  7
  8
 *OUTPUT:
  The First Matrix: 
  3	  4	  5	
  6	  7	  8	
  The Second Matrix: 
  3	  4	
  5	  6	
  7	  8	
  Product of the matrices:
  64	  76	
  109	  130	
*/
 
