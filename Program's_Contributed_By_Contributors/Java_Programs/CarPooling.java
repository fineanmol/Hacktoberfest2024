// https://leetcode.com/problems/car-pooling/
package com.sharan;
// 81% Faster O(n)
public class CarPooling {
    public boolean carPooling(int[][] trips, int capacity) {
        int max = 0;
        int[] arr = new int[1001];
        for (int[] trip : trips) {
            arr[trip[1]] += trip[0];
            arr[trip[2]] -= trip[0];
        }
        for (int i = 0; i < arr.length; i++) {
            max += arr[i];
            if(max > capacity) {
                return false;
            }
        }
        return true;
    }
}
