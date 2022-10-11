// https://leetcode.com/problems/sum-of-even-numbers-after-queries/
package com.sharan;
//Time limit exceeded :/
import java.util.Arrays;

public class QuerySum {
    public static void main(String[] args) {
        int[] arr ={1,2,3,4};
        int[][] queries = {{1,0},{-3,1},{-4,0},{2,3}};
        System.out.println(Arrays.toString(sumEvenAfterQueries(arr,queries)));
    }
    static int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int[] arr = new int[nums.length];
        int l = 0;
        for(int i = 0; i < queries.length; i++){
            int sum = 0;
            for(int j = 0; j < queries[i].length - 1; j++){
                nums[queries[i][j+1]] = nums[queries[i][j+1]] + queries[i][j];
            }
            for(int k = 0; k < nums.length; k++){
                if(nums[k] % 2 == 0){
                    sum+= nums[k];
                }
            }
            System.out.println(sum);
            arr[l] = sum;
            l++;
        }
        return arr;
    }
}
