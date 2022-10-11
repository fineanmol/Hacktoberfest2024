//https://leetcode.com/problems/max-consecutive-ones/
package com.sharan;

public class MaxiumumOnes {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                count++;
                if(count > ans){
                    ans = count;
                }
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
}
