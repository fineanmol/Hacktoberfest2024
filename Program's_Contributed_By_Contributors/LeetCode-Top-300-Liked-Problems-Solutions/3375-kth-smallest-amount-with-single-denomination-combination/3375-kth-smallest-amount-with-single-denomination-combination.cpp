// number theory, binary search, bitmasking
#define ll long long

class Solution {
public:
    ll countLessThanOrEqualToX(vector<int>& coins, ll midX) {
        int m = coins.size();
        int allOnes = (1 << m) - 1;

        ll count = 0;

        // check for all the combinaiton
        for (int mask = 1; mask <= allOnes; mask++) {
            // for all the combination, get the lcm of set bits
            // check the count of set bits
            // if count is odd => add to contribution,
            // if count is even => subtract from contribution

            ll lcmOfSetBits = 1;

            // find lcm of that coins which are in mask
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    lcmOfSetBits = lcm(lcmOfSetBits, coins[j]);
                }
            }

            if (__builtin_popcount(mask) & 1) {
                count += (midX / lcmOfSetBits);
            } else {
                count -= (midX / lcmOfSetBits);
            }
        }
        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        // lower limit to start the binary search
        ll l = 1;

        // higher limit => max-coin = 25, maxk = 2*1e9
        // ~ 25*1e9 + 25 => round of to higher value
        ll r = 1e11;
        ll ans = 0;
        while (l <= r) {
            ll midX = (l + r) / 2;
            ll count = countLessThanOrEqualToX(coins, midX);
            if (count < k) {
                // no of elements less than or equal to is less than k
                // therefore move to right
                l = midX + 1;
            } else {
                ans = midX;
                r = midX - 1;
            }
        }

        return ans;
    }
};