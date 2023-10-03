
//following code is used to concatanate two strings using C++
#include <iostream>
#include <string>
using namespace std;


int main() {
    string s1,s2,result;
    cout<<"Enter First String: "<<endl;
    //getline allows spaces(required if multiple words in a single string separated by spaces)
    //it takes in two arguments 1. The input stream 2. The string variable name
    getline(cin,s1);
    cout<<"Enter Second String: "<<endl;
    getline(cin,s2);
    
    result = s1 +" "+ s2;
    cout<<"-------------------------------------"<<endl;
    cout<<result<<endl;
    cout<<"-------------------------------------"<<endl;
    return 0;
}
//this code is submitted by StarlyHere :)
