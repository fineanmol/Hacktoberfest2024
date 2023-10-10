//LeetCode 232.

class MyQueue{
    public:
    stack<int>input,output;
    myQueue{

    }
    void push(int x){
        input.push(x);
    }
    int pop(){
        int val = peek();
        output.pop();
        return val;
    }
    int peek(){
        if(output.empty()){
            while(input.empty() == false){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();

    }
    bool empty(){
        return input.empty() && output.empty();
    }

};