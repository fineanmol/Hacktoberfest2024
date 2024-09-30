class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Optimal: T.C = O(n) + O(2n), S.C = O(n)
        if(nums.size() == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int it : nums)
            st.insert(it);
        
        for(int it : nums){
            // No previous found! This might be the start
            if(st.find(it - 1) == st.end()){
                int cnt = 1, start = it;
                while(st.find(start + 1) != st.end()){
                    cnt += 1;
                    start = start + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};