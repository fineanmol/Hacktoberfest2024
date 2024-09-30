class Solution {
public:
    unordered_map<int, vector<int>> prime2index;
    unordered_map<int, vector<int>> index2prime;
    void dfs(int index, vector<int>& visitedIndex, unordered_map<int,bool>& visitedPrime){
        if(visitedIndex[index] == true) return;
        visitedIndex[index] = true;

        for(auto &prime : index2prime[index]){
            if(visitedPrime[prime] == true) 
                continue;
            visitedPrime[prime] = true;
            for(auto &index1 : prime2index[prime]){
                if(visitedIndex[index1] == true) continue;
                dfs(index1, visitedIndex, visitedPrime);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int temp = nums[i];
            for (int j = 2; j*j <= nums[i]; j++) {
                if (temp % j == 0) {
                    prime2index[j].push_back(i);
                    index2prime[i].push_back(j);
                    while (temp % j == 0)
                      temp /= j;
                }
            }
            if (temp > 1) {
                prime2index[temp].push_back(i);
                index2prime[i].push_back(temp);
            }
        }

        vector<int> visitedIndex(nums.size(),0);
        unordered_map<int,bool> visitedPrime;
        dfs(0, visitedIndex, visitedPrime);     

        for(int i=0; i<visitedIndex.size(); i++) 
            if(visitedIndex[i] == false) 
                return false;
        return true;    
    }
};



