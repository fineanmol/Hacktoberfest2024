// https://leetcode.com/problems/jewels-and-stones/
package com.sharan;
// O(n^2) 100% Faster.
public class JewelsAndStones {
    public int numJewelsInStones(String jewels, String stones) {
        int count = 0;
        for (int i = 0; i < jewels.length(); i++) {
            for (int j = 0; j < stones.length(); j++) {
                if(jewels.charAt(i) == stones.charAt(j)) count++;
            }
        }
        return count;
    }
}
