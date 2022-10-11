// https://leetcode.com/problems/flipping-an-image/
package com.sharan;
// Asked in google
public class FlippingImage {
    public static int[][] flipAndInvertImage(int[][] arr) {
        for(int i = 0; i < arr.length; i++){
            int start = 0;
            int end = arr[i].length - 1;
            while(start <= end){
                int temp = arr[i][start] ^ 1;
                arr[i][start] = arr[i][end] ^ 1;
                arr[i][end] = temp;
                start++;
                end--;
            }
        }
        return arr;
    }
}
