class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;
        unordered_set<int> st;
        for(int n : nums){
            int abs_n = abs(n);
            if(abs_n > maxi && st.find(-n) != st.end())
                maxi = abs_n;
            st.insert(n);
        }
        return maxi;
    }
};