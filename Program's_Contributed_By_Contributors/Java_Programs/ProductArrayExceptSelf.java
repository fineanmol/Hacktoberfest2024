// https://leetcode.com/problems/product-of-array-except-self/
package com.sharan;
// 100% Faster.
public class ProductArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int left = 1;
        int n = nums.length;
        int[] res = new int[n];
        for(int i = 0;i < n; i++){
            // right side added first.
            if(i>0){
                left = left * nums [i-1];
            }
            res[i] = left;
        }
        int right = 1;
        for(int i= n-1;i >= 0; i--){
            // left side added second.
            if(i < n-1){
                right = right * nums[i+1];
            }
            res[i] *= right;
        }
        return res;
    }
}
