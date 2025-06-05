#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while (n){
            n&=n-1;
            count++;
        }           
        return count;
    }
};