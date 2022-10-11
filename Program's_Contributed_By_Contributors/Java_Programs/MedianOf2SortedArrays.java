// https://leetcode.com/problems/median-of-two-sorted-arrays/
package com.sharan;
// 60.95% Faster 90.89% Less memory (Merge Sort)
public class MedianOf2SortedArrays {
    public static void main(String[] args) {
        int[] nums1 = {1,2};
        int[] nums2 = {3,4};
        System.out.println(findMedianSortedArrays(nums1,nums2));
    }
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] ans;
        ans = merge(nums1,nums2);
        double middle;
        if (ans.length % 2 == 0){
            double a =  ans[ans.length / 2 ];
            double b =  ans[ans.length / 2 - 1];
            return middle = (a + b) / 2;
        }
        return middle = ans[ans.length / 2];
    }
    private static int[] merge(int[] first, int[] second) {
        int[] mix = new int[first.length + second.length];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < first.length && j < second.length) {
            if (first[i] < second[j]) {
                mix[k] = first[i];
                i++;
            } else {
                mix[k] = second[j];
                j++;
            }
            k++;
        }
        while (i < first.length) {
            mix[k] = first[i];
            i++;
            k++;
        }
        while (j < second.length) {
            mix[k] = second[j];
            j++;
            k++;
        }
        return mix;
    }
}
