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
        long int left = 1, right = n;
        long int mid = (left+right)/2;
        long int bad = n;


        while (left<=right){
            mid=(left+right)/2;
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