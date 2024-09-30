class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";

        // making left point to first non space char
        int left = 0;
        while (s[left] == ' ') {
            left++;
        }

        // making right point to last non space char
        int right = s.length() - 1;
        while (s[right] == ' ') {
            right--;
        }

       while(left <= right){
           if(s[left] != ' '){
               temp += s[left];
           }
           else{
               if(s[left - 1] == ' '){ //edge case
                   left++;
                   continue;
               }
               else if(ans == ""){
                   ans = temp;
                   temp = "";
               }
               else{
                   ans = temp + " " + ans;
                   temp = "";
               }
           }
           left++;
       }
       if(ans == ""){
           ans = temp;
       }
       else{
           ans = temp + " " + ans;
       }
       return ans;
    }
};