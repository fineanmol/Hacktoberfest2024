#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& data) {
    string temp = data;
    
    reverse(temp.begin(), temp.end());
    
    if (!data.compare(temp)) {
        return true;
    }
    
    return false;
}


int main(){
    
    if (isPalindrome("WOW")) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
    
return 0;
}

