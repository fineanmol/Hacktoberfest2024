class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int last_el, flag;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (!st.empty() && st.top() * asteroids[i] < 0 && st.top() > 0)
            {
                if (st.top() <= abs(asteroids[i]))
                {
                    flag = 1;
                    while (!st.empty() && st.top() <= abs(asteroids[i]) && st.top() > 0 && flag)
                    {
                        last_el = st.top();
                        if (st.top() == abs(asteroids[i]))
                            flag = 0;
                        st.pop();
                    }
                    if (!st.empty() && st.top() < 0 && flag)
                        st.push(asteroids[i]);
                    if (st.empty() && last_el < abs(asteroids[i]))
                        st.push(asteroids[i]);
                }
            }
            else
            {
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};