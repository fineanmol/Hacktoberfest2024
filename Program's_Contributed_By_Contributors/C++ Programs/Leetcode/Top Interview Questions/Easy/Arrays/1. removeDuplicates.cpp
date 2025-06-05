#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nextNonDuplicate=1;
        for (int i=1;i<nums.size();i++){
            if (nums[i]!=nums[nextNonDuplicate-1]){
                nums[nextNonDuplicate]=nums[i];
                nextNonDuplicate++;
            }
        }
        return nextNonDuplicate;
    }
};