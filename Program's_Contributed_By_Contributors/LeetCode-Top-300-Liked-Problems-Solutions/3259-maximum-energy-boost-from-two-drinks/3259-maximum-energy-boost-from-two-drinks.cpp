class Solution {
public:
    int f(int i, int drink, vector<int> &arr1, vector<int> &arr2, vector<vector<int>> &dp){
        if(i >= arr1.size())
            return 0;

        if(dp[i][drink] != -1) return dp[i][drink];

        int option1 = INT_MIN, option2 = INT_MIN;

        if(drink == 0){
            option1 = arr1[i] + f(i + 1, 0, arr1, arr2, dp);
            option2 = f(i + 1, 1, arr1, arr2, dp);
        }else{
            option1 = arr2[i] + f(i + 1, 1, arr1, arr2, dp);
            option2 = f(i + 1, 0, arr1, arr2, dp);
        }

        return dp[i][drink] = max(option1, option2);
        
        
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return max(f(0, 0, energyDrinkA, energyDrinkB, dp), f(0, 1, energyDrinkA, energyDrinkB, dp));
    }
};