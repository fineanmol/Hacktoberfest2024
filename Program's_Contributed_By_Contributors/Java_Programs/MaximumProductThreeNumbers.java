// https://leetcode.com/problems/maximum-product-of-three-numbers/
package com.sharan;

import java.util.Arrays;
// 61.91% Faster. (Revisit)
public class MaximumProductThreeNumbers {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        // Check last 3 number product and compare it with prod of first 2 numbers and last number
        // because first 3 numbers would give negative answer.
        return Math.max(nums[nums.length-1]*nums[nums.length-2]*nums[nums.length-3],nums[0]*nums[1]*nums[nums.length-1]);
    }
}
