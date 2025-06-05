class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();
        // look into the next day and if you are making profit, just buy it today.
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        }
        return profit;
    }
};