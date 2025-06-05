#include <iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

void printSubstrings(string input) {
    set<string> s1;
   for (int i = 0; i < input.length(); i++) {
       for (int j = i+1; j <= input.length(); j++) {
         // cout<<input.substr(i,j)<<endl;
         s1.insert(input.substr(i,j));
       }
  }
  for(auto x:s1){
   cout<<x<<endl;
  }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}
