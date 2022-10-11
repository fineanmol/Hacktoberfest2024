// https://leetcode.com/problems/check-if-n-and-its-double-exist/
package com.sharan;

import java.util.Arrays;

public class NAndItsDoubleExists {
    public static void main(String[] args) {
        int[] arr ={0,0};
        System.out.println(checkIfExist(arr));
    }
    public static boolean checkIfExist(int[] arr) {
        Arrays.sort(arr);
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr.length; j++){
                // exception for 0 example {0,0}
                if(i==j) continue;
                if(arr[i] == arr[j] * 2){
                    return true;
                }
            }
        }
        return false;
    }
}
