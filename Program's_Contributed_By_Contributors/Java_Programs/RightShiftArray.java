package com.sharan;

import java.util.Arrays;

public class RightShiftArray {
    public static void main(String[] args) {
        int[] arr = {0,10,6,7,8};
        System.out.println("Original array = " + Arrays.toString(arr));
        int shift = 1;
        System.out.println("Shifted array = " + Arrays.toString(shiftTheArray(arr, shift)));
    }
    static int[] shiftTheArray(int[] arr, int shift) {
        for (int i = 1; i <= shift; i++) {
            int start = arr[arr.length-1];
            for (int j = arr.length - 1; j >= 0; j--) {
                if (j-1 >= 0){
                    arr[j] = arr[j-1];
                }
            }
            arr[0] = start;
        }
        return arr;
    }
}
