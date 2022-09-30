//Problem Question : https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

//solution :

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
         if( intervals.size() ==0){
            return v;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];  
       for(auto it : intervals){
           if(temp[1] >= it[0]){
               temp[1] = max(temp[1], it[1]);
           }
           else{
               v.push_back(temp);
               temp = it;
           }
       }
        v.push_back(temp);
        return v;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}