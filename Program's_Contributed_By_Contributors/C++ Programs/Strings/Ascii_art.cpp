#include <iostream>
#include <map>

// Function to convert a character to ASCII art
void printAsciiArt(char ch) {
    // ASCII art for some characters
    std::map<char, std::string> asciiArt = {
        {'A', "  A  \n A A \nAAAAA\nA   A\nA   A\n"},
        {'B', "BBBB \nB   B\nBBBB \nB   B\nBBBB \n"},
        {'C', " CCC \nC   C\nC    \nC   C\n CCC \n"},
        // Add more characters as needed
    };

    // Convert the character to uppercase
    ch = toupper(ch);

    // Print ASCII art for the character
    if (asciiArt.find(ch) != asciiArt.end()) {
        std::cout << asciiArt[ch] << std::endl;
    } else {
        std::cout << "Character not supported for ASCII art." << std::endl;
    }
}

int main() {
    // Get input text from the user
    std::string inputText;
    std::cout << "Enter text to convert to ASCII art: ";
    std::getline(std::cin, inputText);

    // Print ASCII art for each character in the input text
    for (char ch : inputText) {
        printAsciiArt(ch);
    }

    return 0;
}
