//Problem Question : https://leetcode.com/problems/merge-sorted-array/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// Time complexity: O(logn)
// Space Complexity: O(1)
//Solution 1 :
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int k = m ; k <( m+n) ; k++ )
        {
            nums1[k] = nums2[k-m];
        }
        if((m == 0) || (n == 0) )
        {
            return;
        }
        int gap = ceil(((m+n)/2.0));
        while(gap > 0 ){
            int i = 0 ;
            int j =gap;
            while(j < (m+n))
            {
                if(nums1[i] > nums1[j])
                {
                    swap(nums1[i],nums1[j]);
                }
                i++;
                j++;
            }
            if(gap == 1 ){
                break;}
                gap = ceil(gap/2.0);
        }
    }
};

// Time complexity: O(n*m) + O(n)
// Space Complexity: O(1) 
//Solution 2 :
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m ; i <( m+n) ; i++ )
        {
            nums1[i] = nums2[i-m];
        }
        if((nums1.size() == 0) || (nums2.size() == 0) )
        {
            return;
        }
        int i = 0;
        while(i != m )
        {
            if(nums1[i] > nums1[m]){
                swap(nums1[i],nums1[m]);
                sort(nums1.begin() + m ,nums1.end());
            }
            i++;
        }
    }
};

//BRUTEFORCE APPROCH : IF YOU DON'T WANT TO MAKE COMPLEX ;)
//Solution 3 :
// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(1) 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m ; i <( m+n) ; i++ )
        {
            nums1[i] = nums2[i-m];
        }
        if((nums1.size() == 0) || (nums2.size() == 0) )
        {
            return;
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}