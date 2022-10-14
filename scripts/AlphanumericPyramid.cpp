//Enter string that will be the center string of last row of s pyramid and print it in the form of pyramid.
// Input : ABC
// OUTPUT :  A
//          ABA
//         ABCBA
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string letters;

    cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(cin, letters);

    int num_letters = letters.length();

    int position=0;

    // for each letter in the string
    for (char ch: letters) {

        int num_spaces = num_letters - position;
        while (num_spaces > 0) {
            cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (int cur_char=0; cur_char < position; cur_char++) {
            cout << letters.at(cur_char);
        }

        // Display the current 'center' character
        cout << ch;

        // Display the remaining characters in reverse order
        for (int rem_char=position-1; rem_char >=0; --rem_char) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<int>(rem_char);
            cout << letters.at(k);
        }

        cout << endl; // Don't forget the end line
        ++position;
    }

    return 0;
}