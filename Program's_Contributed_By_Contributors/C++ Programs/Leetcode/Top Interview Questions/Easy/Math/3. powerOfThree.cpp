#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n>0 && (int)pow(3,19)%n==0){
            return true;
        }
        else{
            return false;
        }
    }
};