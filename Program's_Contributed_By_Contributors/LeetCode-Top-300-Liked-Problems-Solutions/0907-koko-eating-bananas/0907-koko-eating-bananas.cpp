class Solution {
public:
    long long calcHrs(vector<int>& piles, int hours){
        long long totalHrs = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHrs += ceil((double) 1LL * piles[i] / hours);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        int ans = -1;

        while(low <= high){
            int mid = (low + high) >> 1;
            if(1LL * calcHrs(piles, mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};