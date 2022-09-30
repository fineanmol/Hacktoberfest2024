// Problem Question : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// Solution 1 : Optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            mini = min(mini,prices[i]);
            profit = max(profit,prices[i] - mini);
        }
        return profit;
    }
};

// Solution 2 :  Bruteforce
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            for(int j = i+1 ; j<prices.size() ; j++)
            {
                if(prices[j] > prices[i]){
                    profit = max(prices[j] - prices[i],profit);
                 }
            }
        }
                    return profit;

    }
};
int main(){
ios::sync_with_stdio(0); 
cin.tie(0);

    return 0;
}