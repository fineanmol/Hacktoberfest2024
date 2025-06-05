class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st;
        int cnt = 0;
        for(int n : nums)
            st.insert(n);
        
        for(int n : nums){
            if(st.find(n - diff) != st.end() && st.find(n + diff) != st.end())
                cnt += 1;
        }

        return cnt;
    }
};