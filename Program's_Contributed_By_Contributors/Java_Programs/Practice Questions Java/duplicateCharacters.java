package eteQuestionBank;
import java.util.*;
public class duplicateCharacters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        String str = sc.next();
        String newStr = str + " ";

        for(int i = 0; i<newStr.length()-1; i++){
            if(newStr.charAt(i)==newStr.charAt(i+1)){
                continue;
            }
            else{
                sb.append(newStr.charAt(i));
            }
        }

        System.out.println(sb);
    }
}
