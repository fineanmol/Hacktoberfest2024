package com.sharan;

public class CipherCode {
    public static void main(String[] args){
        String input = "Where are you? Meet me near the clock tower";
        System.out.println(encode(input));
    }
    public static String encode(String s){
        StringBuilder ans = new StringBuilder();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' '){
                count++;
                if (count > 2){
                    ans.append(' ');
                    count = 0;
                }
            }
            else{
                if(count == 0){
                    if(s.charAt(i) == 'a' || s.charAt(i) == 'e' ||  s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u'){
                        ans.append('%');
                    }
                    else{
                        ans.append(s.charAt(i));
                    }
                }
                else if(count == 1){
                    if(Character.toLowerCase(s.charAt(i)) == 'a' || Character.toLowerCase(s.charAt(i)) == 'e' ||  Character.toLowerCase(s.charAt(i)) == 'i' || Character.toLowerCase(s.charAt(i)) == 'o' || Character.toLowerCase(s.charAt(i)) == 'u'){
                        ans.append(s.charAt(i));
                    }
                    else {
                        ans.append('#');
                    }
                }
                else {
                    ans.append(Character.toUpperCase(s.charAt(i)));
                }
            }
        }
        return ans.toString();
    }
}
