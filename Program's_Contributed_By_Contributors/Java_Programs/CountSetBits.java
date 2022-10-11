// https://leetcode.com/problems/number-of-1-bits/
package com.sharan;

public class CountSetBits {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        int len = 0;
        while(len < 32){
            if((n & 1) == 1){
                count++;
            }
            n >>= 1;
            len++;
        }
        return count;
    }
}
