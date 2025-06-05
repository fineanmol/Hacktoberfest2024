#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for (auto num:nums){
            result^=num;
        }
        return result;
    }
};