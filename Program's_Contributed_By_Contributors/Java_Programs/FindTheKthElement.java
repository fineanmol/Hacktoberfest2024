// https://leetcode.com/problems/kth-largest-element-in-an-array/
package com.sharan;
// Not the best solution according to time complexity.
public class FindTheKthElement {
    public static int findKthLargest(int[] nums, int k) {
        for(int i = 0; i < nums.length - 1; i++){
            for(int j = 1; j < nums.length - i; j++){
                if(nums[j-1] > nums[j]){
                    swap(nums,j-1,j);
                }
            }
        }
        return nums[nums.length - k];
    }
    public static void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
