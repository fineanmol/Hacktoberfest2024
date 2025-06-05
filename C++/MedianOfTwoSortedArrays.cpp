class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto i:nums2) nums1.push_back(i);
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        if(n%2)
        {
            return nums1[n/2];
        }
        else
        {
            return (double) (nums1[n/2] + nums1[n/2 - 1]) / 2.0;
        }
        return 0;
    }
};
