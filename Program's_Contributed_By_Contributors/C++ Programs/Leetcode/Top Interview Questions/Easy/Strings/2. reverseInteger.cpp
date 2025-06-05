#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverse=0;
        int pop;
        while (x!=0){
            pop = x % 10;
            x/=10;

            if (reverse > INT_MAX/10 || reverse ==INT_MAX/10 && pop>7)
                return 0;
            if (reverse < INT_MIN/10 || reverse == INT_MIN/10 && pop>7)
                return 0;
            reverse=reverse*10+pop;        
        }   
        return reverse;
    }
};