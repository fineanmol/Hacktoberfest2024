#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1; //i starts as the last element of nums1 and j starts as the last element of nums2
        
        while (i >= 0 && j >= 0) { //While we still have to compare elements in the 2 arrays
            int k = i + j + 1; //k >= 0 and k < nums1.size(). k is the index of the current element in the destination array. 
			                   //k starts at the end of the destination array and goes towards the front.
            nums1[k] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]; //Copy the larger element to the destination and decrement the 
			                   // index of the array from which the value was copied. 
							   //Note that k > i so none of nums1[0], ..., nums1[i] will be overwritten.
        } //Upon termination of this loop, exactly one of i and j will be negative, where i (respectively, j) will be negative 
		  // if and only if all of the elements in nums1 (resp. nums2) have been emplaced into their correct positions.
        if (i == -1) { //Then j >= 0 and only nums2[0], ..., nums2[j] need to be copied into nums1.
            for (int k = 0; k <= j; ++k)
                nums1[k] = nums2[k];
        } //Else j == -1, i >= 0, and we're done since nums1[0], ..., nums1[i] are already correctly emplaced in the array.
        return ;
    }
};