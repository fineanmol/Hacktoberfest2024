class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ans = 0;
        // whenever we encounter a number, it can form k good pairs with previously traversed numbers, where k is the number of times we have seen the number previously.
        for (int num: nums) {
            ans += counts[num];
            counts[num]++;
        }
        
        return ans;
    }
};