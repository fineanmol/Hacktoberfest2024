#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;


class Solution {
public:
    vector<int> array;
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
        array=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int leftSize=array.size();
        for (int i=array.size()-1;i>=0;i--){
            int random = rand()%leftSize;
            int temp = array[i];
            array[i]=array[random];
            array[random]=temp;
            leftSize--;
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */