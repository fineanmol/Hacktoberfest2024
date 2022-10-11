// https://leetcode.com/problems/power-of-four/
package com.sharan;
// If the number is a power of four it could be divided back to 4.
// Example 64 / 4 = 16 which divisible by 4, 16 / 4 = 4 till it reaches one 4 / 4 = 1.(True Case).
// Example 24 / 4 = 6 which is not further divisible by 4 hence false.(False Case).
public class IsPowerOfFour {
    public boolean isPowerOfFour(int n) {
        return isPowerFour(n);
    }
    public static boolean isPowerFour(int n){
        if(n == 1){
            return true;
        }
        if(n == 0){
            return false;
        }
        if(n % 4 != 0){
            return false;
        }
        return isPowerFour(n / 4);
    }
}
