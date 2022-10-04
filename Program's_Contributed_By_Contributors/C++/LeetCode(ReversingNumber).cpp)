class Solution {
public:
    int reverse(int x) {
        long int reqNumber = 0;
            while (x != 0) {
            reqNumber = (10 * reqNumber) + (x % 10);
            x = x / 10;
            }
        if(reqNumber> 2147483648-1||reqNumber<-2147483648){
            return 0;
        }
        return reqNumber;
        
    }
};
