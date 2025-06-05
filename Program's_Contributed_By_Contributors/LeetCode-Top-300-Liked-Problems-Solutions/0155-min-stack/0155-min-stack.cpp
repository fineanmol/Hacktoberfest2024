class MinStack {
    stack<long long> s;
    long long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int x) {
        long long val = x;
        if(s.empty()){
            mini = val;
            s.push(val);
        }
        else{
            if(val < mini){
                s.push(2 * val * 1LL - mini); //  Modifying the mini value to keep track of previous mini
                mini = val;
            }
            else
                s.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long el = s.top();
        s.pop();
        if(el < mini)
            mini = 2 * mini * 1LL - el; // Getting back to previous mini
    }
    
    int top() {
        if(s.empty()) return -1;
        long long el = s.top();
        if(el < mini) return mini;
        return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */