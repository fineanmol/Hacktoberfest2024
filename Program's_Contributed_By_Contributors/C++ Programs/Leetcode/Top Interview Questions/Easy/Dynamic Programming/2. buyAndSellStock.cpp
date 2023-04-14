#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minElement=INT_MAX;
        int maxProfit=0;
        for (int i=0;i<prices.size();i++){
            minElement=min(prices[i],minElement);
            maxProfit=max(maxProfit,prices[i]-minElement);
        }
        return maxProfit;
    }
};