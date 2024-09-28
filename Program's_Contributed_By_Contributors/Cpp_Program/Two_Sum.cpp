#include <iostream>
#include <sstream> // For stringstream to convert string to number
#include <string>
using namespace std;

// Function to convert string input to a double and add two numbers
double convertAndAdd(string input1, string input2)
{
    double num1, num2;

    // Convert the first input to double
    stringstream ss1(input1);
    ss1 >> num1;

    // Convert the second input to double
    stringstream ss2(input2);
    ss2 >> num2;

    // Return the sum
    return num1 + num2;
}

int main()
{
    string input1, input2;

    // Taking two numbers as input from the user
    cout << "Enter the first number: ";
    cin >> input1;
    cout << "Enter the second number: ";
    cin >> input2;

    // Add the numbers and display the result
    double sum = convertAndAdd(input1, input2);
    cout << "The sum of the two numbers is: " << sum << endl;

    return 0;
}
