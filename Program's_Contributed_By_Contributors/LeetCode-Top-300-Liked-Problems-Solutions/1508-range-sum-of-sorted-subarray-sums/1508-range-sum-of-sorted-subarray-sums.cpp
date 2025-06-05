class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1000000007;
        vector<int> prefix(n + 1, 0);

        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        vector<int> ans;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                ans.push_back((prefix[j] - prefix[i - 1]) % MOD);
            }
        }

        sort(ans.begin(), ans.end());

        int res = 0;
        for(int i = left - 1; i < right; i++)
            res = (res + ans[i]) % MOD;
        
        return res;
    }
};