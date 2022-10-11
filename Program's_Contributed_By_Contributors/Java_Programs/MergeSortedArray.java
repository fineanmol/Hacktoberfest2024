// https://leetcode.com/problems/merge-sorted-array/
package com.sharan;

import java.util.Arrays;
public class MergeSortedArray {
    public static void main(String[] args) {
        int[] nums1 = {0,0,3,0,0,0,0,0,0};
        int[] nums2 = {-1,1,1,1,2,3};
        int m = 3;
        int n = 6;
        merge(nums1,m,nums2,n);
    }
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int j = 0;
        for (int i = m; i < nums1.length; i++) {
                nums1[i] = nums2[j];
                j++;
            }
        Arrays.sort(nums1);
        System.out.println(Arrays.toString(nums1));
    }
}