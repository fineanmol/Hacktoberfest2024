class Solution {
public:
    int minCnt(int val, int cnt){
        if (cnt < 0) return 1e9;
        if (cnt == 0) return 0;
        if (cnt % 3 == 0) return cnt / 3;
        if (cnt % 3 == 1) return (cnt - 1) / 3 + 1;
        if (cnt % 3 == 2) return (cnt - 2) / 3 + 1;
        return 0;
    }
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
        }

        int cnt = 0;

        for(auto it : mp){
            if(it.second == 1)
                return -1;
            else if(minCnt(it.first, it.second) < 1e9)
                cnt += minCnt(it.first, it.second);
            else 
                return -1;
        }

        return cnt;

    }
};