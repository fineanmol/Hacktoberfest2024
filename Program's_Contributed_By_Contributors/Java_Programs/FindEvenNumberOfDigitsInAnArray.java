// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/
package com.sharan;

public class FindEvenNumberOfDigitsInAnArray {
    public int findNumbers(int[] nums) {
        int mainCount = 0;
        for(int i = 0; i < nums.length; i++){
            if(isEven(nums[i])){
                mainCount++;
            }
        }
        return mainCount;
    }
    public boolean isEven(int i){
        int count = 0;
        while(i > 0){
            i = i / 10;
            count++;
        }
        if(count % 2 == 0){
            return true;
        }
        return false;
    }
}
