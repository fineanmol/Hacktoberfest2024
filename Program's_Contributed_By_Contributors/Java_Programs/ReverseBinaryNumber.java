// https://leetcode.com/problems/reverse-bits/
package com.sharan;
// Geeks for geeks solution. (refer)
public class ReverseBinaryNumber {
    // you need treat n as an unsigned value
    public static int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            ans = ans << 1;
            if((n & 1) == 1)
                ans++;
            System.out.println(ans);
            n = n >>> 1;
        }
        return ans;
    }
}
