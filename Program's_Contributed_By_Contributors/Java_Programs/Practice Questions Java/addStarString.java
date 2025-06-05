package eteQuestionBank;
import java.util.*;
public class addStarString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        StringBuilder sb = new StringBuilder();
        sb.append(sc.next());
        int m, n;

        m = sc.nextInt();
        n = sc.nextInt();

        sb.insert(m, "*");
        sb.insert(n+1, "*");

        System.out.println(sb);


    }
}
