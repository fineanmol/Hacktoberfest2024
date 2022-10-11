// https://leetcode.com/problems/create-target-array-in-the-given-order/
package com.sharan;
import java.util.ArrayList;
import java.util.Arrays;

public class CreateTargetArray {
    public static void main(String[] args) {
        int[] arr = {4,2,4,3,2};
        int[] nums = {0,0,1,3,1};
        System.out.println(Arrays.toString(createTargetArray(arr,nums)));
    }
    public static int[] createTargetArray(int[] nums, int[] index) {
            ArrayList<Integer> arr = new ArrayList<>();
            for(int i = 0; i < nums.length; i++){
                arr.add(index[i],nums[i]);
            }
            for (int j = 0; j < nums.length; j++){
                nums[j] = arr.get(j);
            }
            return nums;
        }
}
