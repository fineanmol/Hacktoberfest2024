#include <iostream>
#include <string>
using namespace std;

void powerSet(string s, string o, int index){
    if (index == s.size()){
        cout << o << endl;
        return;
    }

    powerSet(s, o, index + 1);
    powerSet(s, o += s[index], index + 1);
}

int main(){

    string n = "abc";
    string output = "";
    powerSet(n, output, 0);

    return 0;
}