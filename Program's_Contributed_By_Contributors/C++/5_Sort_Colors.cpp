// Problem Question :  https://leetcode.com/problems/sort-colors/
// WARN : DUTCH NATIONAL FLAG ALGORITHM IS HERE (><)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

//Solution 1(DUTCH NATONAL FLAG ALGO.)
class Solution {
public:
    void sortColors(vector<int>& nums) {
      int low = 0;
        int mid = 0;
        int hi = nums.size() - 1;
        
        while(mid<=hi)
        {
            switch(nums[mid])
            {
                    // If Element is 0
                case 0 :
                    swap(nums[mid++],nums[low++]);
                    break;
                    // If Element is 1
                case 1 : 
                    mid++;
                    break;
                    // If Element is 2
                case 2 :
                    swap(nums[mid],nums[hi--]);
                    break;
            }
        }
    }
};


// Solution 2(MY SOLN.)
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0;
        for(auto i : nums)
        {
            if(i==0)
                c0++;
            else if(i==1)
                c1++;
        }
        for(int i = 0 ; i < c0 ; i++){
            nums[i] = 0;
        }
        for(int i = c0 ; i < (c0+c1) ; i++){
            nums[i] = 1;
        }
        for(int i = (c0+c1); i < nums.size() ; i++ ){
            nums[i] = 2;
        }
    }
};

int main(){
ios::sync_with_stdio(0); 
cin.tie(0);
    return 0;
}