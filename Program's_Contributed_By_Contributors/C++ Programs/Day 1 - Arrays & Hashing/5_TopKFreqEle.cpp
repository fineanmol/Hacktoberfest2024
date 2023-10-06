/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& entry : frequencyMap) {
            buckets[entry.second].push_back(entry.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) {
                        break;
                    }
                }
            }
        }

        return result;
    }
};