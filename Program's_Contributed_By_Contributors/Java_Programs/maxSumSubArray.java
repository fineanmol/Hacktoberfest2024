import java.util.* ;
import java.io.*; 
public class Solution {
    public static long maxSubarraySum(int[] arr, int n) {
        long max = 0;
        long sum = 0;
        for(int i=0; i<arr.length; i++)
        {
            sum = sum + arr[i];
            max = Math.max(sum, max);
            if(sum<0)
                sum = 0;
        }
        return max;
    }
}
