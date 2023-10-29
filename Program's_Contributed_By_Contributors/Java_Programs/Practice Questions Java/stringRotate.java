package eteQuestionBank;
import java.util.*;
public class stringRotate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int key = sc.nextInt();

        String rotated = rotate(str, key);
        String reversed = reverse(rotated);

        if(rotated.equals("-1")){
            System.out.println(rotated);
        }
        else{
            System.out.println(rotated);
            System.out.println(reversed);
        }

    }

    static String rotate(String str, int n){
        int len = str.length();

        if(n>len){
            return "-1";
        }

        return str.substring(n) + str.substring(0, n);
    }

    static String reverse(String str){
        StringBuilder res = new StringBuilder(str);
        return res.reverse().toString();
    }
}
