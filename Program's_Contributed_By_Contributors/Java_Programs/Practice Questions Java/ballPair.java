package eteQuestionBank;
import java.util.*;

public class ballPair {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        int cnt = 0;

        for(int i = 0; i<n; i++){
            int val = arr[i]/2;
            cnt = val + cnt;
        }

        System.out.println(cnt);
    }
}
