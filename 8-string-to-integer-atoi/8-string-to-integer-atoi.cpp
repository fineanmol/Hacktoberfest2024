class Solution {
public:
    int myAtoi(string input) {
        int sign = 1; 
        int result = 0; 
        int index = 0;
        int n = input.size();
        
        while (index < n && input[index] == ' ') { 
            index++; 
        }
        
        if (index < n && input[index] == '+') {
            sign = 1;
            index++;
        } else if (index < n && input[index] == '-') {
            sign = -1;
            index++;
        }
        
        while (index < n && isdigit(input[index])) {
            int digit = input[index] - '0';

            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
                  
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = 10 * result + digit;
            index++;
        }
        
        return sign * result;
    }
};