#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <unordered_map> 

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int num = x^y;
        while (num) {
            // Odd numbers have rightmost bit set 
            res += num % 2;
            num >>= 1;
        }
        return res;
    }
};