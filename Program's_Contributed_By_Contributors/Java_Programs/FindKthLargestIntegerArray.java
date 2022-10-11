// Time Limit Exceeded.
package com.sharan;

import java.math.BigInteger;

public class FindKthLargestIntegerArray{
    public static String kthLargestNumber(String[] nums, int k) {
        for(int i = 0; i < nums.length; i++){
            for(int j = 1; j < nums.length - i; j++){
                BigInteger n1 = new BigInteger(nums[j]);
                BigInteger n2 = new BigInteger(nums[j-1]);
                if (n2.compareTo(n1) > 0) {
                    String temp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums[nums.length - k];
    }
}
