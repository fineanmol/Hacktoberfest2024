package com.sharan;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class IntersectionOfToArrays {
    public static void main(String[] args) {
        int[] nums1 = {1,2,2,1};
        int[] nums2 = {2,2};
        System.out.println(Arrays.toString(intersection(nums1,nums2)));
    }
    public static Object[] intersection(int[] nums1, int[] nums2) {
        List<Integer> arr = new ArrayList<Integer>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        for(int i = 1; i < nums1.length; i++){
            if(nums1[i] != nums1[i - 1]){
                for(int j = 1; j < nums2.length; j++){
                    if(nums2[j] != nums2[j - 1]){
                        if(nums1[i] == nums2[j]){
                            arr.add(nums1[i]);
                        }
                    }
                }
            }
        }
        return arr.toArray();
    }
}
