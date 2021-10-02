import java.util.*;
import java.lang.*;

class Knapsack { 

    static int knapSack(int W, int wt[], int val[], int n) 
    { 
        int i, w; 
        int K[][] = new int[n + 1][W + 1]; 
  
        for (i = 0; i <= n; i++) { 
            for (w = 0; w <= W; w++) { 
                if (i == 0 || w == 0) 
                    K[i][w] = 0; 
                else if (wt[i - 1] <= w) 
                    K[i][w] = Math.max( 
                        val[i - 1] + K[i - 1][w - wt[i - 1]], 
                        K[i - 1][w]); 
                else
                    K[i][w] = K[i - 1][w]; 
            } 
        } 
  
        return K[n][W]; 
    } 
  
    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter no. of elements n: ");
        int n = sc.nextInt();
        System.out.print("Enter max. weight W: ");
        int W = sc.nextInt();

        int[] val = new int[n];
        int[] wt = new int[n];

        System.out.print("Enter value of elements");
        for(int i=0;i<n;i++){
            val[i] = sc.nextInt();
        }

        System.out.print("Enter weight of elements");
        for(int i=0;i<n;i++){
            wt[i] = sc.nextInt();
        }

        System.out.println(knapSack(W, wt, val, n)); 
    } 
} 
