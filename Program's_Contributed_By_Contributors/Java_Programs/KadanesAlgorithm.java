// 
package com.sharan;

public class KadanesAlgorithm {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int currentSum = maxSum;
        for(int i = 1; i < nums.length; i++){
            currentSum = Math.max(nums[i] + currentSum, nums[i]);
            maxSum = Math.max(currentSum, maxSum);
        }
        return maxSum;
    }
}
