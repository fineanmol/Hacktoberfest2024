// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
package com.sharan;

import java.util.Arrays;

// 90.84% O(n)
public class MinimizeMaximumPairSumArray {
    class Solution {
        public int minPairSum(int[] nums) {
            Arrays.sort(nums);
            int maxSum = 0;
            int start = 0;
            int end = nums.length - 1;
            while(start < end){
                if(maxSum < nums[start] + nums[end]){
                    maxSum = nums[start] + nums[end];
                }
                start++;
                end--;
            }
            return maxSum;
        }
    }
}
