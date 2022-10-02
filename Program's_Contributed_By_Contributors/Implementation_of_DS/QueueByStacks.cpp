#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        int curr = s1.top();
        s1.pop();
        return curr;
    }

    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
