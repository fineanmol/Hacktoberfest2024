class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0)
            return true;
        if(x < 0 || x % 10 == 0)
            return false;
        int num = x;
        long int sum = 0;
        while(x)
        {
            sum = (sum * 10) + (x % 10);
            x /= 10;
        }
        return (sum == num);
    }
};
