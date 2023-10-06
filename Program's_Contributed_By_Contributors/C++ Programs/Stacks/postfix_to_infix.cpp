#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (!isOperator(c)) {
            st.push(string(1, c));
        } else {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();

            string newExpr = "(" + operand1 + " " + c + " " + operand2 + ")";
            st.push(newExpr);
        }
    }

    return st.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);

    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}