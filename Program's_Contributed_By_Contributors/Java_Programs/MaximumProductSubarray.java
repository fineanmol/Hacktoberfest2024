// https://leetcode.com/problems/maximum-product-subarray/
package com.sharan;
// 5% Faster O(n^2)
public class MaximumProductSubarray {
    public int maxProduct(int[] nums) {
        int maxProd = nums[0];
        for(int i = 0; i < nums.length; i++){
            maxProd = Math.max(nums[i],maxProd);
            int prod = nums[i];
            for(int j = i+1; j < nums.length; j++){
                prod *= nums[j];
                maxProd = Math.max(prod,maxProd);
            }
        }
        return maxProd;
    }
}
