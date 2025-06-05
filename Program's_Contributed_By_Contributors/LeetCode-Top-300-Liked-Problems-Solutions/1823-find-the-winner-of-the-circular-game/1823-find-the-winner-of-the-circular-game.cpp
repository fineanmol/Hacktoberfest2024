class Solution {
public:
    int winnerHelper(int n, int k) {
        if (n == 1) return 0;
        return (winnerHelper(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) { return winnerHelper(n, k) + 1; }
    
};