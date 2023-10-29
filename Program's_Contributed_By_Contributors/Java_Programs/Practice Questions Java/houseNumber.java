package eteQuestionBank;
import java.util.*;
public class houseNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        int ele;
        int cnt = 1;
        int k = 1;

        while(cnt<=n){
            ele = 3 * k + 2;
            if (ele % m != 0) {
                System.out.println(ele);
                cnt++;
            }
            k++;
        }

    }
}
