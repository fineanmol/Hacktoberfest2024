class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // T.C => O(n log k), S.C => O(n + k)
        
        if (k == nums.size()) {
            return nums;
        }

        map<int, int> counts; // value, frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // frequency, element

        for(auto i : nums){
            counts[i]++;
        }

        for(auto i : counts){
            min_heap.push({i.second, i.first}); // frequency, element
            if(min_heap.size() > k)
                min_heap.pop(); // Less frequency value will be popped out
        }

        vector<int> res;
        while(k--){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;
    }
};