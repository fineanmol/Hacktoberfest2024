class Solution {
public:
    int reverse(int x) {

        int MAX = pow(2,31) - 1;
        int MIN = pow(2,31) * (-1);

        if(x > MAX || x < MIN)
                return 0;

        long int rev = 0, digit;

        while(x)
        {
            digit = x % 10;
            x /= 10;
            rev = (rev * 10) + digit; 
            if(rev > MAX  || rev < MIN )
                return 0;
            
        }

        return rev;

    }
};
