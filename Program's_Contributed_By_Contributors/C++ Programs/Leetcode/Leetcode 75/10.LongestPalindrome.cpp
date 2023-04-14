// https://leetcode.com/problems/longest-palindrome/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
    int result = 0;
    bool odd = false;
    unordered_map<char,int> counts;
    for (auto i:s){
        counts[i]++;
    }
    for (auto j:counts){
        if (j.second%2==0){
            result+=j.second;
        }
        else{
            odd = true;
            result+=j.second-1;
        }
    }
    if (odd) result++;
    return result;
}
};
int main(){
    // Call the function
    string s = "abccccdd";
    Solution s1;
    int result = s1.longestPalindrome(s);
    cout << result << endl;
}
