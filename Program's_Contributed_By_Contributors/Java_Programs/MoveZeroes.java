// https://leetcode.com/problems/move-zeroes/
package com.sharan;
// O(n2)
public class MoveZeroes {
    public void moveZeroes(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            for(int j = i + 1; j < nums.length; j++){
                if(nums[i] == 0){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                else{
                    break;
                }
            }
        }
    }

}
