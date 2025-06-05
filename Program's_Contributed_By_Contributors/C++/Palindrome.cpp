#include <iostream>
using namespace std;

bool checkPalindrome(string s, int start, int end){
    if(start>=end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }
    return checkPalindrome(s, start+1, end-1);
}

int main() {

    string a;
    cin>>a;

    cout<< checkPalindrome(a, 0, a.size()-1);

    return 0;
}