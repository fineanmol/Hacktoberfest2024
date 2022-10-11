// https://leetcode.com/problems/binary-number-with-alternating-bits/
package com.sharan;
// 23 % faster solution.
public class AlternatingBits {
    public boolean hasAlternatingBits(int n) {
        StringBuilder answer = new StringBuilder();
        while(n > 0){
            if((n & 1) == 1){
                answer.append(1);
            }
            else{
                answer.append(0);
            }
            n >>= 1;
        }
        return !answer.toString().contains("11") && !answer.toString().contains("11");
    }
// 100% Faster solution O(1) space complexity.
    public boolean hasAlternatingBitsBetter(int n) {
        while( n != 0)
        {
            // if the next and previous bits of a number are same then there xor will be 0.
            if(((n&1) ^ ((n>>1)&1)) == 0)
                return false;
            n = n>>1;
        }
        return true;
    }
}
