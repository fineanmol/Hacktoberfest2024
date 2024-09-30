class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int v1 = st.top(); st.pop();
                int v2 = st.top(); st.pop();
                if (token == "+") {
                    st.push(v2 + v1);
                } else if (token == "-") {
                    st.push(v2 - v1);
                } else if (token == "*") {
                    st.push(v2 * v1);
                } else if (token == "/") {
                    st.push(v2 / v1);
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};