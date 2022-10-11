// https://leetcode.com/problems/palindrome-number/
package com.sharan;
// 39.50% faster.
public class PalindromeNumber {
    public static void main(String[] args) {
        int x = 121;
        System.out.println(x);
    }
    public static boolean isPalindrome(int x) {
        int ans = 0;
        int temp = x;
        if (x < 0) {
            return false;
        } else {
            while (temp > 0) {
                ans = ans * 10 + temp % 10;
                temp /= 10;
            }
            return ans == x ;
        }
    }
}
