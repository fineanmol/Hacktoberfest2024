#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        pascal[0]={1};
        pascal[1]={1,1};
        for (int i=2;i<numRows;i++){
            pascal[i]=pascal[i-1];
            for (int j=1;j<i-1;j++){
                // pascal[i].insert(j,pascal[i-1][j-1]+pascal[i-1][j])
            }
        }
    }
};