/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

class Solution {
public:
    bool isOperator(string c) {
        return (c == "+" || c == "/" || c == "-" || c == "*");
    }

    int operation(int a, int b, string c) {
        if (c == "+")
            return a + b;
        else if (c == "/")
            return a / b;  // Reversed operands (b/a) to (a/b)
        else if (c == "-")
            return a - b;  // Reversed operands (b-a) to (a-b)
        else if (c == "*")
            return a * b;
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int result;
        for (auto str : tokens) {
            if (!isOperator(str)) {
                stack.push(stoi(str));
            } 
            else {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                result = operation(a, b, str);
                stack.push(result);  // Push the result back onto the stack
            }
        }
        return stack.top();  // Return the final result on the stack
    }
};
