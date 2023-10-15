//Leetcode 155

class MinStack {
    stack <long long> st;
    long long mini;
public:
    MinStack() {
        while(st.empty()==false)st.pop();
        mini = INT_MAX;
        
    }
    void push(int value) {
        long long val = value;
        if (st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if (val < mini){

        // modify value when val < mini

                st.push(2*val*1ll - mini);
                mini = val;
            }
            else st.push(val);
        } 
        
    }
    
    void pop() {
        if (st.empty()) return;
        long long elt = st.top();
        st.pop();
        if (el<mini){

        modify mini when elt < mini

            mini = 2 * mini - elt;
        }        
    }
    
    int top() {
        if (st.empty()) return -1;
        long long elt = st.top();
        if(elt < mini) return mini;
        return el;
        
    }
    
    int getMin() {
        return mini;
        
    }
};
