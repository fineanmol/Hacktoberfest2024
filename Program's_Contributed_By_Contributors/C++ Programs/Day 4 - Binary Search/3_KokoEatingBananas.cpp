/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

https://leetcode.com/problems/koko-eating-bananas/submissions/
*/

class Solution{
public:
    int minEatingSpeed(vector<int> &piles, int h){
        unsigned int left = 1;
        unsigned int right = 1000000000;
        while (left <= right){
            unsigned int mid = left + (right - left) / 2;
            if (canEatintime(piles, mid, h))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
    bool canEatintime(vector<int> &piles, unsigned int k, unsigned int h){
        unsigned int hours = 0;
        for (unsigned int pile : piles){
            unsigned int div = pile / k;
            hours += div;
            if (pile % k != 0)
                hours++;
        }
        return hours <= h;
    }
};