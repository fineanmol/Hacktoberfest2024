package com.sharan;

public class MinimumSizeSubarraySum {
    public static void main(String[] args) {
        int[] arr = {2,3,1,2,4,3};
        int target = 7;
        System.out.println(minSubArrayLen(target, arr));
    }
    public static int minSubArrayLen(int target, int[] nums) {
        int length = nums.length + 1;
        int temp = 0;
        int ptr = 0;
        int i = 0;
        while(i < nums.length || temp >= target) {
            if (temp < target) {
                temp += nums[i];
                i++;
            }
            else {
                length = Math.min(length, i - ptr);
                temp -= nums[ptr];
                ptr++;
            }
        }
        return length == nums.length + 1 ? 0 : length;
    }
}
