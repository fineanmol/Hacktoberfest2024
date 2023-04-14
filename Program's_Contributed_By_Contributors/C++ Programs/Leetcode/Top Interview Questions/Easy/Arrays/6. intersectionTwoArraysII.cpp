#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int p1=0,p2=0;

        while (p1<nums1.size() && p2<nums2.size()){
            if (nums1[p1]==nums2[p2]){
                intersection.push_back(nums1[p1++]);
                p2++;
            }
            else if (nums1[p1]>nums2[p2]){
                p2++;
            }
            else{
                p1++;
            }
        }
        return intersection;
    }
};