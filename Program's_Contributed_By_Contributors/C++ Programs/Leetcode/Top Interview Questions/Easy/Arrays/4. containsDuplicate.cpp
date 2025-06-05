#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map> 

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> countArray;
        for (int i=0;i<nums.size();i++){
            if (countArray[nums[i]]){
                return true;
            }
            countArray[nums[i]]++;
        }
        return false;
    }
};