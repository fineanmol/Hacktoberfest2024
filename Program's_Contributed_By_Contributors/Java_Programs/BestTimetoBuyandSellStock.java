// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
package com.sharan;
// 100% Faster (Refered Solution)
public class BestTimeToSellStock {
    public static void main(String[] args) {
        int[] arr = {7,1,5,3,6,4};
        System.out.println(maxProfit(arr));
    }
    public static int maxProfit(int[] prices) {
        int max = 0;
        int min=prices[0];
        for(int i = 1;i < prices.length; i++){
            System.out.println(min);
            if(min < prices[i]) {
                max = Math.max(prices[i] - min, max);
            }
            else {
                min = prices[i];
            }
        }
        return max;
    }
}
