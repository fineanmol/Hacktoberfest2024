class Solution {
public:
    int passThePillow(int n, int time) {
        int round = time / (n - 1) ;
        if(round % 2 == 1){
            return n - (time % (n - 1));
        }
        return (time % (n - 1)) + 1;
    }
};