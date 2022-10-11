// https://leetcode.com/problems/counting-bits/
package com.sharan;

import java.util.Arrays;

public class CountingBits {
    public static void main(String[] args) {
        int n = 2;
        System.out.println(Arrays.toString(countBits(n)));
    }
    public static int[] countBits(int n) {
        int[] ans = new int[n+1];
        ans[0] = 0;
        int j = 1;
        for(int i = 1; i <= n; i++){
            int c = i;
            while(c > 0){
                if((c & 1) == 1){
                    ans[j] += 1;
                }
                c = c >> 1;
            }
            j++;
        }
        return ans;
    }
}
