package eteQuestionBank;
import java.util.*;
public class substring10and00 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        StringBuilder sb = new StringBuilder();
        String temp = "";

        for(int i = 0; i<str.length(); i++){
            if((temp + str.charAt(i) + str.charAt(i+1)).equals("10") || (temp + str.charAt(i) + str.charAt(i+1)).equals("00")){

            }
        }
    }
}
