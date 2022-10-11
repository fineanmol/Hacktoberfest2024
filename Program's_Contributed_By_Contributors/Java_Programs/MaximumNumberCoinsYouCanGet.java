// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
package com.sharan;
// 23.3 Faster O(n).
// (Revisit).
// This was a pretty fun question! I decided to share my thinking and how I got to my solution.
// Thought Process
// • We are given coins in a multiple of 3 so that Alice, Bob, and I all get the same amount of coins.
// • We can grab any 3 coins at a time, creating a pile in which we all take a coin from.
// • Alice takes the highest value, we take the next highest value, and Bob always takes the lowest value.
// So, if Alice is always going to take the most valuable coin,
// we always need to select piles that include the 2 highest value coins and the lowest value coin that
// are left in the main pile. This will ensure we get the max value possible with Alice always being a
// little more greedy than we are. Forget about Bob.
// In order to do this, we can sort the array and take every second coin from the,
// end until we've taken our third of the coins.
// But wait, let's not forget about Bob just yet! He is still of use to us.
// Since we all get a third, that means bob will always get the first third of the sorted array [0... (n/3)-1].
// We can just start iterating by 2 through the array at i = n/3 until we reach n-1.
// Instead of iterating from the end which makes it a little easier to read.

import java.util.Arrays;

public class MaximumNumberCoinsYouCanGet {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int ans = 0;
        int n = piles.length/3;
        for(int i = n; i < piles.length; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
}
