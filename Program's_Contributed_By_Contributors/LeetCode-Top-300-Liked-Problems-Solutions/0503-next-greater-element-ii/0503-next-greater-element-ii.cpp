class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);

        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && nums[i % n] >= st.top())
                st.pop();

            if(i < n){
                if(!st.empty()) 
                    nge[i] = st.top();
            }

            st.push(nums[i % n]);
        }

        return nge;
    }
};