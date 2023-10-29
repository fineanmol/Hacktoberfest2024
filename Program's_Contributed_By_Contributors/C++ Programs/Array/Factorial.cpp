#include <iostream>

// Function to calculate the factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    if (number < 0) {
        std::cout << "Factorial is undefined for negative numbers." << std::endl;
    } else {
        unsigned long long result = factorial(number);
        std::cout << "Factorial of " << number << " is " << result << std::endl;
    }
    
    return 0;
}
