#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,right=0;

        while (right<nums.size()){
            if (nums[right]==0){
                right++;
            }
            else{
                nums[left++]=nums[right++];
            }
        }
        while (left<nums.size())
            nums[left++]=0;                
    }
};