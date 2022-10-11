// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
package com.sharan;
// Unsolved.
import java.util.Arrays;

public class BitsSort {
    public static void main(String[] args) {
        int[] arr = {1024,512,256,128,64,32,16,8,4,2,1};
        System.out.println(Arrays.toString(sortByBits(arr)));
    }
    public static int[] sortByBitss(int[] arr) {
        int[] bits = new int[arr.length];
        int[] ans = new int[arr.length];
        for(int i = 0; i < arr.length; i++){
            int count = 0;
            int n = arr[i];
            while(n > 0){
                if((n & 1) == 1){
                    count++;
                }
                n >>= 1;
            }
            bits[i] = count;
        }
        int l = 0;
        Arrays.sort(arr);
        for(int j = 0; j <= 14; j++){
            for(int k = 0; k < bits.length; k++){
                if(j == bits[k]){
                    ans[l] = arr[k];
                    l++;
                }
            }
        }
        return ans;
    }
public static int[] sortByBits(int[] arr) {
    int[] bits = new int[arr.length];
    int[] ans = new int[arr.length];
    for(int i = 0; i < arr.length; i++){
        int count = 0;
        int n = arr[i];
        while(n > 0){
            if((n & 1) == 1){
                count++;
            }
            n >>= 1;
        }
        bits[i] = count;
    }
    int l = 0;
    int length = 0;
    for(int j = 0; j <= 14; j++){
        int innerLength = 0;
        for(int k = 0; k < bits.length; k++){
            if(j == bits[k]){
                length++;
                ans[l] = arr[k];
                l++;
            }
            if(j != 0 && j == bits[k]){
                innerLength++;
            }
        }
        for(int m = innerLength; m < length; m++){
            for(int n = m + 1; n < length - m; n++){
                if(ans[n] > ans[n-1]){
                    int temp = ans[n];
                    ans[n] = ans[n-1];
                    ans[n-1] = temp;
                }
            }
        }
    }
    return ans;
}
}
