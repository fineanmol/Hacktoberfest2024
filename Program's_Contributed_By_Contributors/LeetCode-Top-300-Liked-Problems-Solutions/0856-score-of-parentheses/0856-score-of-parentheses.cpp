class Solution {
public:
    // int scoreOfParentheses(string s) {
    //     stack<int> st;
    //     int sum = 0;
    //     for(char c : s){
    //         if(c == '(')
    //             st.push(-1);
    //         else{
    //             int cur = 0;
    //             while(st.top() != -1){
    //                 cur += st.top();
    //                 st.pop();
    //             }
                    
    //             st.pop();
    //             st.push(cur == 0 ? 1 : cur * 2);
    //         }
    //     }
    //     while(!st.empty()){
    //         sum += st.top();
    //         st.pop();
    //     }
    //     return sum;
    // }
    int scoreOfParentheses(string s) {
        int n = s.length(), t = 0, sum = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                t += 1;
            else{
                t -= 1;
                if(s[i - 1] == '(')
                    sum += 1 << t;
            }
        }
        return sum;
    }
};