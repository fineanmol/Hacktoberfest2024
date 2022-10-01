//Problem Question : https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// Solution : 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //First Transpose matrix means {i,j} <-> {j,i}
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Reverse every row 
        for(int i = 0 ; i < n ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
int main(){
ios::sync_with_stdio(0); 
cin.tie(0);

    return 0;
}