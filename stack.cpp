#include <iostream>
#include <stack>

using namespace std;

// Stack: It is data structure which is LIFO method to store data
// LIFO: Last In First Out  
// FILO: First In Last Out
// Last which is added is the first to out
// it is used in text editor or undo and redo action and front and back button on the browser
// First functions associated with stacks
/**
 * empty(): stack is empty or not
 * size(): size of the stack
 * top(): gives top of the stack
 * push(): adding elements in stack
 * pop(): removing elements in stack
*/

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();

    }
}

int main(){
    
    stack<int> nums;
    
    //adding elememts in stack
    nums.push(1);
    nums.push(2);
    nums.push(3);
    nums.pop();
    // removing elements from stack
    // nums.pop();
    // nums.pop();
    // nums.pop();

    print(nums);

    // if(nums.empty()) cout << "Stack is empty" << endl;
    // else cout << "Stack is not empty" << endl;

    // cout << "Stack size is" << nums.size() << endl;

   

    system("pause>0");
}