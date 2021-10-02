/*
Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces
*/

import java.util.Scanner;
class RodCutting {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            Solution ob = new Solution();
            System.out.println(ob.cutRod(arr, n));
        }
    }
}


class Solution{
    public int cutRod(int price[], int n) {
        
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int[][] t = new int[n+1][n+1];
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=Math.max(price[i-1]+t[i][j-arr[i-1]],t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        return t[n][n];
    }
}
