#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long,int> hashMap;
        vector<int> solution;
        for (int i=0;i<nums.size();i++){
            hashMap[nums[i]]=i;
        }        
        for (int i=0;i<nums.size();i++){
            if (hashMap.find(target-nums[i])!=hashMap.end() && hashMap[target-nums[i]]!=i){
                solution.push_back(hashMap[target-nums[i]]);
                solution.push_back(i);
                return solution;
            }
        }
        return solution;
    }
};