import java.io.*;
  
class GFG {
    private static int LongSubarrSeq(
        int[] arr1, int[] arr2)
    {
        int M = arr1.length;

        int N = arr2.length;

        int maxL = 0;
        
        int[][] DP = new int[M + 1][N + 1];

        for (int i = 1; i <= M; i++) {

            for (int j = 1; j <= N; j++) {
  
                if (arr1[i - 1] == arr2[j - 1]) {

                    DP[i][j] = 1 + DP[i - 1][j - 1];
                }

                else {
  
                    DP[i][j] = DP[i][j - 1];
                }
            }
        }
        for (int i = 1; i <= M; i++) {
  
            for (int j = 1; j <= N; j++) {
  
                maxL = Math.max(maxL, DP[i][j]);
            }
        }
        return maxL;
    }

    public static void main(String[] args)
    {
        int[] arr1 = { 4, 2, 3, 1, 5, 6 };
        int[] arr2 = { 3, 1, 4, 6, 5, 2 };
        System.out.println(LongSubarrSeq(arr1, arr2));
    }
}
