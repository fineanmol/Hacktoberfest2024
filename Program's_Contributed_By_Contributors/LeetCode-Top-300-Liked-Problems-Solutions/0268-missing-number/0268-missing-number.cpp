class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, i = 0;
        for(i = 0; i < nums.size(); i++){
            sum += (i - nums[i]);
        }
        return sum + i;
    }
};