class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"},result = "";
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int len = sizeof(roman)/sizeof(roman[0]);
        int i = 0;

        while(num && i < len){
            if(num - values[i] >= 0)
            {
                result += roman[i];
                num -= values[i];
            }
            else
                i++;
        }
        return result;
    }
};