class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums)
            mp[num]++;
        
        int ans = 0;

        for(auto it : mp){
            if(k == 0){ // k == 0 ? When both nums[i] and nums[j] are same, so check if their count > 1?
                ans = it.second > 1 ? ans + 1 : ans;
            }
            else if(mp.find(k + it.first) != mp.end())
                ans += 1;
        }
        return ans;
    }
};
