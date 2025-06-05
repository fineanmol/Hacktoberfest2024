#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size()-1;
        int left = 0;
        char temp;

        while (left < right){
            temp = s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }        
    }
};