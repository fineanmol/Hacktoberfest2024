#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

    class Solution {
    public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string current = string(1,board[i][j]);
            if (current != ".") {
            if (!seen.insert(current + "row'" + string(1,i)).second ||
                !seen.insert(current + "column" + string(1,j)).second||
                !seen.insert(current + "subblock" + string(1,i / 3) + "-" + string(1,j / 3)).second) {
                return false;
            }
            }
        }
        }
        return true;
    }
    };



