class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int> s;
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() && temp[s.top()] <= temp[i]) 
                s.pop();
            if(!s.empty()) 
                ans[i] = s.top() - i;
            s.push(i);
        } 
        return ans;
    }
};