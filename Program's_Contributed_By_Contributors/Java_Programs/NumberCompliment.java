// https://leetcode.com/problems/number-complement/
// https://leetcode.com/problems/complement-of-base-10-integer/
// Same question.
package com.sharan;

public class NumberCompliment {
    public static int findComplement(int n) {
        int ans = 0;
        int offset = 1;
        while(n > 0){
            if((n & 1) != 1){
                ans |= offset;
            }
            n >>= 1;
            offset <<= 1;
        }
        return ans;
    }
}
