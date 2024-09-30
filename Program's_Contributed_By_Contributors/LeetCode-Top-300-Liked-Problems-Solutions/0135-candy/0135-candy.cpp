class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;

        // initialize vector with 1 as every kid gonna get 1 candy
        vector<int> candies(n,1);

        /* We need to check for both previous and next child */

        // left to right traversal
        for(int i = 1; i < n; i++){
            // if rating is more but candies are less or equal not fair increase it by 1
            if(ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]){
               candies[i] = candies[i-1] + 1; 
            }
        }

        // right to left traversal
        for(int i = n-2; i >= 0; i--){
            // if rating is more but candies are less or equal not fair increase it by 1
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
               candies[i] = candies[i+1] + 1; 
            }
        }
        
        int totalSum = accumulate(candies.begin(), candies.end(), 0);
        return totalSum;
    }
};