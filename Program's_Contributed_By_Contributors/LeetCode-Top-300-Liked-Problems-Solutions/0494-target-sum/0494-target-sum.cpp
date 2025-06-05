class Solution {
public:
    int f(int ind, int target, vector<int>& nums) {
        if (ind < 0) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }
        
        int notTake = f(ind - 1, target + nums[ind], nums);
        int take = f(ind - 1, target - nums[ind], nums);

        return notTake + take;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n - 1, target, nums);
    }
};