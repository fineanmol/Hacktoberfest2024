#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int>& prices) {
    // Initialize variables to track minimum price and maximum profit
    int minPrice = INT_MAX;
    int maxProfit = 0;

    // Iterate through the price array
    for (int price : prices) {
        // Update the minimum price if the current price is lower
        if (price < minPrice) {
            minPrice = price;
        }
        // Calculate the potential profit and update maxProfit if it's higher
        else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    // Example stock prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // Calculate maximum profit
    int profit = maxProfit(prices);
    
    // Output the result
    cout << "Maximum profit: " << profit << endl;

    return 0;
}
