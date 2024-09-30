class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        while (a != 0 || b != 0 || c != 0) {
            if ((c & 1) == 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++; // it is enough if any one of the bit is set to zero
                }
            } else {
                answer += (a & 1) + (b & 1); // (a & 1) + (b & 1) gives us the count of bits that are different from 0 in both a and b.
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
};