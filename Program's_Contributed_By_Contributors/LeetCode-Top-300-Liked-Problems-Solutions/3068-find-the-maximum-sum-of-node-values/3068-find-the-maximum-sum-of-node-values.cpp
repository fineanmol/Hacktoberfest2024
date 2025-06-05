class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<int> netChange;
        long long nodeSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            netChange.push_back((nums[i] ^ k) - nums[i]);
            nodeSum += 1ll * nums[i];
        }
        
        // Sort netChange in decreasing order
        sort(netChange.begin(), netChange.end(), greater<int>());
        
        for (int i = 0; i < netChange.size(); i += 2) {
            // If netChange contains odd number of elements break the loop
            if (i + 1 == netChange.size()) {
                break;
            }
            long long pairSum = netChange[i] + netChange[i + 1];
            
            // Include in nodeSum if pairSum is positive
            if (pairSum > 0) {
                nodeSum += pairSum;
            }
        }
        return nodeSum;
    }
};