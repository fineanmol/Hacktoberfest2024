#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> repeat;

    for (auto i : s) {
      repeat[i]++;
    }

    for (int i = 0; i < s.length(); i++) {
      if (repeat[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};