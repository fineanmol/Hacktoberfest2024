class Solution {
public:
    int binarySearch(vector<int>& nums, long long target) {
        int left = 0, right = nums.size() - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                index = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index;
    }
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Initialize prefix sum array
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            // Using binary search to find the index of the element just less than or equal to queries[i]
            int it = binarySearch(nums, queries[i]);
            
            // Calculate operations needed for left and right parts
            long long left = (1LL * (it + 1) * queries[i]) - (it >= 0 ? prefix[it] : 0);
            long long right = prefix[n - 1] - (it >= 0 ? prefix[it] : 0) - 1LL * (n - (it + 1)) * queries[i];
            
            ans.push_back(left + right);
        }
        return ans;
    }
};
