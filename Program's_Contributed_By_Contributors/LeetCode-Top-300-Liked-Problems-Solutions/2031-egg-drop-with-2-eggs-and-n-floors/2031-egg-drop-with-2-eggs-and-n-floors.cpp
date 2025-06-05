class Solution {
public:
    int twoEggDrop(int n) {
        int i = 1, j = 1;
        while(j < n){
            i++;
            j += i;
        }
        return i;
    }
};