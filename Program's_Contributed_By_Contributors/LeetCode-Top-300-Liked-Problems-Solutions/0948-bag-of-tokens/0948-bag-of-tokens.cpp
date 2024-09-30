class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int left = 0, right = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while(left <= right){
            // face up
            if(tokens[left] <= power){
                power -= tokens[left];
                left += 1;
                score += 1;
            }
            // face down
            else if(score >= 1 && left < right){
                power += tokens[right];
                right -= 1;
                score -= 1;
            }
            else
                return score;
        }
        return score;
    }
};