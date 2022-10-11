package com.sharan;

import java.util.Arrays;

public class LeftShiftTheArray {
    public static void main(String[] args) {
        int[] arr = {0,5,6,7,8};
        System.out.println("Original array = " + Arrays.toString(arr));
        int shift = 3;
        System.out.println("Shifted array = " + Arrays.toString(shiftTheArray(arr, shift)));
    }
    static int[] shiftTheArray(int[] arr, int shift) {
        for (int i = 0; i < shift; i++) {
            int start = arr[0];
            for (int j = 0; j < arr.length; j++) {
                if (j+1 < arr.length){
                    arr[j] = arr[j+1];
                }
            }
            arr[arr.length-1] = start;
        }
        return arr;
    }
}
