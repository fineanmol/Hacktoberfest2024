#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int n){
    if(s.size() == 0){
        s.push(n);
        return;
    }


    int a = s.top(); 
    s.pop();
    insertAtBottom(s, n);
    s.push(a);
}

void reverseStack(stack<int> &s){
    if(s.size() == 0){
        return;
    }

    int n = s.top();
    s.pop();
    reverseStack(s);

    insertAtBottom(s, n);

}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    //insertAtBottom(s, 0);
    cout<<"Before : ";
    print(s);
    cout<<endl;

    reverseStack(s);
    
    cout<<"After : ";
    print(s);
    cout<<endl;
    
    return 0;
}