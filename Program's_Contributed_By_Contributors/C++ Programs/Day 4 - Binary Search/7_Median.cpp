/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalLength = m + n;
        int i = 0, j = 0;
        std::vector<int> merged;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }

        if (totalLength % 2 == 0) {
            // If totalLength is even, return the average of two middle elements
            int mid1 = (totalLength / 2) - 1;
            int mid2 = totalLength / 2;
            return (double)(merged[mid1] + merged[mid2]) / 2.0;
        } else {
            // If totalLength is odd, return the middle element
            int mid = totalLength / 2;
            return (double)merged[mid];
        }
    }
};