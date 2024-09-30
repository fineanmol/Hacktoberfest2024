class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st; // [num, minLeft] => monotonically decreasing
        int curMin = nums[0];

        for(int n : nums){
            while(!st.empty() && n >= st.top().first)
                st.pop();
            if(!st.empty() && n < st.top().first && st.top().second < n)
                return true;
            
            st.push({n, curMin});
            curMin = min(curMin, n);
        }

        return false;
    }
};