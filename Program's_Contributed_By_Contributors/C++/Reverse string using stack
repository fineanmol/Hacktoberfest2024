// C++ program to reverse a string using stack
#include <bits/stdc++.h>
using namespace std;
 
// A structure to represent a stack
class Stack {
public:
    int top;
    unsigned capacity;
    char* array;
};
 
// function to create a stack of given
// capacity. It initializes size of stack as 0
Stack* createStack(unsigned capacity)
{
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array
        = new char[(stack->capacity * sizeof(char))];
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(Stack* stack) { return stack->top == -1; }
 
// Function to add an item to stack.
// It increases top by 1
void push(Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
// Function to remove an item from stack.
// It decreases top by 1
char pop(Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
 
// A stack based function to reverse a string
void reverse(char str[])
{
    // Create a stack of capacity
    // equal to length of string
    int n = strlen(str);
    Stack* stack = createStack(n);
 
    // Push all characters of string to stack
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
 
    // Pop all characters of string and
    // put them back to str
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}
 
// Driver code
int main()
{
    char str[] = "GeeksQuiz";
 
    reverse(str);
    cout << "Reversed string is " << str;
 
    return 0;
}
