// https://leetcode.com/problems/sort-the-people

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for (int i = 0;i<heights.size();i++){
            for (int j = 0;j<heights.size()-i-1;j++){
                if (heights[j+1] >heights[j]){
                    swap(heights[j],heights[j+1]);
                    swap(names[j],names[j+1]);
                }
            }
        }
        
        return names;
    }
};