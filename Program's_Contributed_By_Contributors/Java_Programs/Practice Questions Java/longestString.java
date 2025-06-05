package eteQuestionBank;
import java.util.*;
public class longestString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        String[] words = str.split(" "); // ['my', 'name', 'is', 'aadarsh']
        int maxLength = 0;

        for(int i =0; i< words.length; i++){
            if(words[i].length()>maxLength){
                maxLength = words[i].length();
            }
        }

        System.out.println(maxLength);

    }
}
