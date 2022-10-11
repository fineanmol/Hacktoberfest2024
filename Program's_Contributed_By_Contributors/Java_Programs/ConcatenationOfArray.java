// https://leetcode.com/problems/concatenation-of-array/submissions/
package com.sharan;

import java.util.Arrays;

public class ConcatenationOfArray {
    public static void main(String[] args) {
        int[] arr = {1,2,3};
        System.out.println(Arrays.toString(getConcatenation(arr)));
    }
    static int[] getConcatenation(int[] nums) {
        int j = 0;
        int arr[] = new int[nums.length * 2];
        for(int i = 0;i < nums.length; i++){
            arr[i] = nums[i];
            j = i;
        }
        int k = 0;
        j+=1;
        while(j < arr.length){
            arr[j] = nums[k];
            k++;
            j++;
        }
        return arr;
    }
}
