package eteQuestionBank;
import java.util.*;
public class luckyNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();

        int res = solution(n);
        System.out.println(res);

    }

    static boolean isValid(int n){
        String str = Integer.toString(n);
        for(int i = 1; i<str.length(); i++){
            if(str.charAt(i)<str.charAt(i-1)){
                return false;
            }
        }
        return true;
    }

    static int solution(int n){
        while (!isValid(n)) {
            n--;
        }
        return n;
    }
}
