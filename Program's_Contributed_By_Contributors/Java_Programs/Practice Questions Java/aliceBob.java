package eteQuestionBank;
import java.util.*;

public class aliceBob {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();

        int[] alice = new int[n];
        int[] bob = new int[n];

        for(int i = 0; i<n; i++){
            alice[i] = sc.nextInt();
        }

        for(int i = 0; i<n; i++){
            bob[i] = sc.nextInt();
        }

        int aliceCount = 0;
        int bobCount = 0;
        int res;

        for(int i = 0; i<n; i++){
            if(alice[i]>bob[i]*2){
                aliceCount++;
            }
        }

        for(int i = 0; i<n; i++){
            if(bob[i]>alice[i]*2){
                bobCount++;
            }
        }

        res = min(aliceCount, bobCount);

        System.out.println(res);
    }

    static int min(int a, int b){
        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }
}
