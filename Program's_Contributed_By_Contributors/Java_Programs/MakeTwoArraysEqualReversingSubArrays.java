// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
package com.sharan;

import java.util.Arrays;
// 55.49 Faster
public class MakeTwoArraysEqualReversingSubArrays {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        for(int i = 0 ; i < arr.length; i++){
            if(arr[i] != target[i]){
                return false;
            }
        }
        return true;
    }
// 99.72% O(n) Solution.
    public boolean canBeEqualBit(int[] target, int[] arr) {
        int xorArr = 0;
        int xorTarget = 0;
        int prodTarget = 1;
        int prodArr = 1;
        for(int i = 0; i < arr.length; i++){
            xorArr ^= arr[i];
            xorTarget ^= target[i];
            prodTarget *= target[i];
            prodArr *= arr[i];
        }
        return xorArr == xorTarget && prodTarget == prodArr;
    }
}
