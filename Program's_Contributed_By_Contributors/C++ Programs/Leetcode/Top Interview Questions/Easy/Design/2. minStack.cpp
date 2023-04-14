#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map> 

using namespace std;


class MinStack {
public:
    stack<int> s;
    stack<int> minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minVal.empty() || val<=minVal.top()){
            minVal.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if (s.top()==minVal.top()){
            minVal.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minVal.top();
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