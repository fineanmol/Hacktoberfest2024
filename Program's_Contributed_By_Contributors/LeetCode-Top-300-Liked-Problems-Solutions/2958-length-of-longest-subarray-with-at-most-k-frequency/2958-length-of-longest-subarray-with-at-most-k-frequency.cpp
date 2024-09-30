class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int left = 0, right = 0, maxLen = 0;

        while(right < n && left <= right){
            mp[nums[right]]++;
            while(mp[nums[right]] > k && left <= right){
                mp[nums[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};