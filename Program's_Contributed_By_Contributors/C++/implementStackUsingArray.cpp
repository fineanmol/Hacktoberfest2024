//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

// Function to push an integer into the stack.
void MyStack ::push(int x)
{
    // Your Code
    top++; // increment the top variable to point to thee top element in the array
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top == -1) // it tells that the  the array is empty i.e nowhere to point to
        return -1;
    else
        return arr[top--]; // after removing the element point to the lower element
}
