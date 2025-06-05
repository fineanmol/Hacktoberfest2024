// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int pos = 1;
        
        if (nums.size()==1){
            return 1;
        }
        
        for (int i = pos;i<nums.size();i++){
            while (i<nums.size() && nums[i-1]==nums[i])
                i++;
            if (i<nums.size())
                nums[pos++] = nums[i];
        }
        
        return pos;
    }
};