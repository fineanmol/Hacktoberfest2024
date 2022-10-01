#include <iostream>
#include <stack>
using namespace std;

void deleteMiddleHelper(stack<int> &s, int index){
    if(index == 1){
        s.pop();
        return;
    }

    int n = s.top();
    s.pop();
    deleteMiddleHelper(s, index-1);
    s.push(n);
}

void deleteMiddle(stack<int> &s){
    if(s.size()==0){
        return;
    }
    
    int index = s.size()/2 + 1;

    deleteMiddleHelper(s, index);
}


int main() {

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMiddle(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}