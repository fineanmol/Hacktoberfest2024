#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string inputString) {
    stack<char> charStack; // Create a stack of characters
    string reversedString = "";

    // Push each character of the input string onto the stack
    for (char c : inputString) {
        charStack.push(c);
    }

    // Pop characters from the stack to construct the reversed string
    while (!charStack.empty()) {
        reversedString += charStack.top(); // Get the top character
        charStack.pop(); // Pop the top character
    }

    return reversedString;
}

int main() {
    string inputString = "Hello, World!";
    string reversedResult = reverseString(inputString);
    cout << reversedResult << endl; // Print the reversed string
    return 0;
}