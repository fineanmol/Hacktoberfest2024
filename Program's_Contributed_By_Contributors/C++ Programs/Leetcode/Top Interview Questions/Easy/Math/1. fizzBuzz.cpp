#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> fizz;
        for (int i=1;i<=n;i++){
            if (i%3==0 && i%5==0){
                fizz.push_back("FizzBuzz");
            }
            else if (i%3==0){
                fizz.push_back("Fizz");
            }
            else if (i%5==0){
                fizz.push_back("Buzz");
            }
            else{
                fizz.push_back(to_string(i));
            }
        }
        return fizz;
    }
};