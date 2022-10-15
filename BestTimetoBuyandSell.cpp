class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minimum=prices[0];
        //maxpro refers to maximum profit
        int maxpro=0;
        for(int i=0;i<prices.size();i++){
            minimum=min(prices[i],minimum);
            maxpro=max(maxpro,prices[i]-minimum);
            }
        return maxpro;
        }

};
