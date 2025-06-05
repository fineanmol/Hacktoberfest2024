class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0;
        int range = INT_MAX;
        while(right < n){
            sum += nums[right];
            while(sum >= target){
                range = min(range, right - left + 1);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        return range == INT_MAX ? 0 : range;
    }
};