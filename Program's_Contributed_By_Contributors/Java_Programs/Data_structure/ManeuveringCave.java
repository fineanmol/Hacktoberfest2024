//DP problem
//Recurrsion
// Maneuvering a Cave Problem

import java.util.*;
public class Main
{
    static int maneuvering_cave(int m, int n)
    {
        int[] dp = new int[n];
        dp[0] = 1;
  
        for (int i = 0; i < m; i++) 
        {
            for (int j = 1; j < n; j++) 
            {
                dp[j] += dp[j - 1];
            }
        }
  
        return dp[n - 1];
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int m = sc.nextInt();
		System.out.println(maneuvering_cave(m, n));
	}
}
