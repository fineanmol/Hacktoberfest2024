// Not from leetcode.
package com.sharan;

public class ReverseRecursion {
    public static void main(String[] args) {
        System.out.println(reverseRecursion(0,983741));
    }
    public static int reverseRecursion(int ans, int n){
        if(n == n % 10){
            return ans * 10 + n % 10;
        }
        ans = ans * 10 + n % 10;
        return reverseRecursion(ans,n/10);
    }
}
