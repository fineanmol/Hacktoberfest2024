/* Leetcode 477. Total Hamming Distance
Code contributed by Akarshit batra for Hacktoberfest 2022


The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Example 2:

Input: nums = [4,14,4]
Output: 4

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 109
The answer for the given input will fit in a 32-bit integer.
 */

/* Expalanation for the code 
    we will calculate the total number of set bits and unset bits at the i'th bit of each number int they array/vector and multiply the ones 
    and zeros then add it to the answer and return it at the end 
    for eg we take 4 14 2
   their binary representation is as follow
   4  = 0100
   14 = 1110
   2  = 0010
   now the 1st bit from right contain 3 0's and 0 1's so if we mutlipy both we (3*0) we get zero so zero
   is added in the answer. 
   Similary for the next i bits we do the same and get the answer as 6.

*/




#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<31;i++){
             int zero=0;
            int one =0;
            for(int j=0;j<nums.size();j++){
                if( (nums[j] & (1<<i))){
                       one++;
                }else{
                    zero++;
                }
            }
            //cout<<zero<<" "<<one<<endl; 
            ans+= zero*one;
        }
        return ans;
    }
};


int main()
{
    std::vector<int> v={4 ,14,2};
    Solution s1;
    int k=s1.totalHammingDistance(v);
    cout<<k<<endl;
    return 0;
}