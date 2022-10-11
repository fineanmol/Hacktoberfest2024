// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
package com.sharan;
// 21.96% O(n^2).
public class MaximumProductTwoElementsArray {
    public int maxProduct(int[] nums) {
        int maxProd = 0;
        for(int i = 0; i < nums.length - 1; i++){
            for(int j = i + 1; j < nums.length; j++){
                maxProd = Math.max(((nums[i]-1) * (nums[j]-1)), maxProd);
            }
        }
        return maxProd;
    }
}
