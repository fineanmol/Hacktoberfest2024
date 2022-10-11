// https://leetcode.com/problems/find-greatest-common-divisor-of-array/
package com.sharan;

public class GCDArray {
    public static void main(String[] args) {
        int[] arr ={2,5,6,9,10};
        System.out.println(findGCD(arr));
    }
    // approach just check the smallest number and largest number GCD.(Slower approach).
    public static int findGCD(int[] nums) {
        int defaultValue = 1;
        for(int i = 0; i < nums.length; i++){
            for(int j = 1; j < nums.length; j++){
                if(nums[j] < nums[j-1]){
                    int temp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = temp;
                }
            }
        }
        for(int k = 1 ;k <= nums[0] && k <= nums[nums.length - 1]; k++){
            if(nums[0] % k == 0 && nums[nums.length - 1] % k == 0){
                defaultValue = Math.max(defaultValue,k);
            }
        }
        return defaultValue;
    }
    // 100% Faster Solution.
    public static int findGCDFastest(int[] nums) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        //  Find the minimum and maximum in the array.
        for (int i = 0, numsLength = nums.length; i < numsLength; i++) {
            int num = nums[i];
            if (num < min) {
                min = num;
            }
            if (num > max) {
                max = num;
            }
        }
        return gcd(min,max);
    }
    // GCD using Euclidean Algorithm.
    public static int gcd(int a, int b){
        if(a == 0){
            return b;
        }
        return gcd(b % a, a);
    }
}
