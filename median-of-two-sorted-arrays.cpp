//SOLUTION FOR LEETCODE problem of finding median fo two sorted arrays 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int N = m + n;
        vector<int> merged(N, 0);

        int i, j, k;
        i = j = k = 0;
        while(i<m && j<n) {
            if(nums1[i] < nums2[j])
                merged[k++] = nums1[i++];
            else
                merged[k++] = nums2[j++];
        }
        while(i<m)
            merged[k++] = nums1[i++];
        while(j<n) 
            merged[k++] = nums2[j++];

        if(N&1) 
            return merged[N/2];
        else
        return (merged[(N/2)-1] + merged[N/2]) / 2.0;
    }
};
