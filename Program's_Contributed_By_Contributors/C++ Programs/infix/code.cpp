#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 100

template <class T>
class Stack
{
    T stack[SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void push(T x)
    {
        if (top >= SIZE - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++top] = x;
    }

    T pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return stack[top--];
    }

    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top >= (SIZE - 1));
    }
    T tos()
    {
        return stack[top];
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
            cout << stack[i] << "\t";
        cout << endl;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int Precedence(char c)
{
    return (c == '^') ? 3 : (c == '*' || c == '/') ? 2
                        : (c == '+' || c == '-')   ? 1
                                                   : -1;
}
string toPostFix(const string &exp)
{
    Stack<char> s;
    string postfix;
    for (int i = 0; i < exp.length(); i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
            postfix += exp[i];
        else if (exp[i] == '(' || exp[i] == '^')
            s.push(exp[i]);
        else if (exp[i] == ')')
        {
            while (s.tos() != '(')
                postfix += s.pop();
            s.pop(); // pop '('
        }
        else if (isOperator(exp[i]))
        {
            if (s.isEmpty())
                s.push(exp[i]);
            else if (Precedence(exp[i]) <= Precedence(s.tos()))
            {
                while (Precedence(exp[i]) <= Precedence(s.tos()) && !s.isEmpty())
                {
                    postfix += s.pop();
                }
                s.push(exp[i]);
            }
            else
                s.push(exp[i]);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

string reverse(const string &exp)
{
    string reverse;
    Stack<char> stack;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
            stack.push(')');
        else if (exp[i] == ')')
            stack.push('(');
        else
            stack.push(exp[i]);
    }
    while (!stack.isEmpty())
    {
        reverse += stack.pop();
    }
    return reverse;
}

string pre(const string &exp)
{

    string prefix = reverse(exp);

    prefix = toPostFix(prefix);

    prefix = reverse(prefix);
    return prefix;
}

void postevaluate(const string &exp)
{
    Stack<int> s;
    int operand1, operand2;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            s.push(exp[i] - '0');
        else if (isOperator(exp[i]))
        {
            operand2 = s.pop();
            operand1 = s.pop();
            switch (exp[i])
            {
            case '^':
                s.push(pow(operand1, operand2));
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;

            default:
                break;
            }
        }
    }
    cout << "The result of the postfix expression " << exp << " = " << s.tos() << endl;
}

char pairOf(char c)
{
    return (c == ')') ? '(' : ((c == '}') ? '{' : '[');
}
void checkParenthesis(string exp)
{
    Stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.tos() == pairOf(exp[i]))
                s.pop();
            else
            {
                cout << exp << " = Parenthesis not balanced";
                return;
            }
        }
    }
    if (s.isEmpty())
        cout <<  " Balanced ";
    else
        cout << exp << "   not balanced";
}

int main()
{
    string exp;
    cout << "Enter string? in infix :  ";
    cin >> exp;
    cout << "Enter postfix for evaluation: " << endl;
    string postfix;
    cin >> postfix;
    cout << "Postfix: " << toPostFix(exp);
    cout << "\nPrefix: " << pre(exp);
    pre(exp);
    postevaluate(postfix);
    checkParenthesis(exp);
}