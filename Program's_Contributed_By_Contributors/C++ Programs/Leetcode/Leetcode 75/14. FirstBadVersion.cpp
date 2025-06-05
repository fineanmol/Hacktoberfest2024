// https://leetcode.com/problems/first-bad-version/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l = 1;
        long int r = n-1;
        long int mid = (l+r)/2
        long int bad = n;

        while (l<=r){
            mid = (l+r)/2;
            if (isBadVersion(mid)){
                bad=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return bad;
    }
};

