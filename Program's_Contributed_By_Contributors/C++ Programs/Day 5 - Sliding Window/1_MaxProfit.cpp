/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheap = *max_element(prices.begin(),prices.end()), maxProfit = 0;
        for(auto i: prices){
            if(i < cheap)
                cheap = i;
            if(maxProfit < i - cheap)
                maxProfit = i - cheap;
        }
        return maxProfit;
    }
};