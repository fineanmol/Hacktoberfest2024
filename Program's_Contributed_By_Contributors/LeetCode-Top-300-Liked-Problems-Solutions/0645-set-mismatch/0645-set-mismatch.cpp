class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        int dup = -1, miss = -1;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) != st.end())
                dup = nums[i];

            st.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(st.find(i + 1) == st.end())
                miss = i + 1;
        }
        return {dup, miss};
    }
};