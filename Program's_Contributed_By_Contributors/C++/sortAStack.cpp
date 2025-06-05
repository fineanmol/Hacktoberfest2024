#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &s, int temp){
    if((s.top() < temp) || s.empty()){
        s.push(temp);
        return;
    }

    int num = s.top();
    s.pop();
    insert(s, temp);
    s.push(num);
}

void sortAStack(stack<int> &s){
    if(s.size()<=1){
        return;
    }

    int temp = s.top();
    s.pop();
    sortAStack(s);
    insert(s, temp);
}

int main() {

    stack<int> s;
    s.push(0);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(3);

    //insert(s, 3);

    sortAStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }


    return 0;
}