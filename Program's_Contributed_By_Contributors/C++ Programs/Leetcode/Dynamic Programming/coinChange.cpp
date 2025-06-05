#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> req(amount+1,0);

        req[0]=0;
        
        for (int i=1;i<amount+1;i++){
            for (auto c:coins){
                if (i-c>=0)
                    req[i]=min(req[i],1+req[i-c]);
            }
        }
        if (req[amount]!=amount+1){
            return req[amount];
        }
        else[
            return -1;
        ]

        
    }
};