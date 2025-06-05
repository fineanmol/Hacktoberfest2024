#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello, ";
    std::string str2 = "world!";
    
    // Concatenate str2 to str1 using the + operator
    std::string result = str1 + str2;
    
    // Print the concatenated string
    std::cout << result << std::endl;
    
    return 0;
}
