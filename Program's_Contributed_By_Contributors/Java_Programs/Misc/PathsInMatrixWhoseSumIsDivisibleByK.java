//Question Link= https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/


import java.util.*;

public class PathsInMatrixWhoseSumIsDivisibleByK{

    public static void main(String[] args) throws Exception { 
      int grid[][]={{5,2,4},{3,0,5},{0,7,2}};
      int k = 3;
      System.out.println(numberOfPaths(grid,k));
    }


    public static int numberOfPaths(int[][] grid, int k) {
        int [][][]dp = new int[grid.length][grid[0].length][k];
        int mod =1000000000+7;
        return helper(grid,k,grid.length-1,grid[0].length-1,0,dp,mod);
    }

    public static int helper(int grid[][],int k,int i,int j,int sum,int dp[][][],int mod){

        sum += grid[i][j];
        sum %= k;
        if(i<0 || j<0) return 0;
        if(i==0 && j==0){
            if((sum)%k==0) return 1;
            else return 0;
        }

        if(dp[i][j][sum]!=0) return dp[i][j][sum];

        int left=helper(grid,k,i,j-1,(sum+grid[i][j])%k,dp,mod);
        int top=helper(grid,k,i-1,j,(sum+grid[i][j])%k,dp,mod);

        dp[i][j][sum]=(left+top)%mod;
        return dp[i][j][sum];
        
    }
  }
