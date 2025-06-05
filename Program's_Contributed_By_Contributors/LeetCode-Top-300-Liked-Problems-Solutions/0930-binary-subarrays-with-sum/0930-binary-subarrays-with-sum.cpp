class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0, sum = 0;
        unordered_map<int, int> freq;

        for(int num : nums){
            sum += num;
            if(sum == goal)
                cnt += 1;

            if(freq.find(sum - goal) != freq.end())
                cnt += freq[sum - goal];
            
            freq[sum] += 1;
        
        }
        return cnt;
    }
};