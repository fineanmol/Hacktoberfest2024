class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int start = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[start]){
                ans += 1LL * (i - start) * nums[start];
                start = i;
            }else if(i == nums.size() - 1){
                ans += 1LL * (i - start) * nums[start];
            }
        }
        return ans;
    }
};
