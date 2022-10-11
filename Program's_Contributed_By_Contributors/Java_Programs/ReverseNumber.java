// https://leetcode.com/problems/reverse-integer/
package com.sharan;

public class ReverseNumber {
    public int reverse(int n) {
        long ans = 0;
        while(n != 0){
            int c = n % 10;
            ans = ans * 10 + c;
            n /= 10;
        }
        if (ans > Integer.MAX_VALUE || ans < Integer.MIN_VALUE){
            return 0;
        }
        else {
            return (int) ans;
        }
    }
}
