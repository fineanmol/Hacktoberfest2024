package eteQuestionBank;
import java.util.*;
public class subStringFill {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();

        int rem = str.length()%n;

        String fill = sc.next();

        for(int i = 0; i<=rem; i++){
            str = str + fill;
        }

        int len = str.length();

        ArrayList<String> arr = new ArrayList<>();

        for(int i = 0; i<str.length(); i = i + n){
            arr.add(str.substring(i,i+n));
        }

        System.out.println(arr);
    }
}
