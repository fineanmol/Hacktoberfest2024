package eteQuestionBank;
import java.util.*;

public class freshnessVal {
    public static void main(String[] args) {
        int a, b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        int[] fresh = new int[a];
        int[] cost = new int[a];

        for(int i = 0; i<a; i++){
            fresh[i] = sc.nextInt();
        }

        for(int i = 0; i<a; i++){
            cost[i] = sc.nextInt();
        }

        int totalCost = 0;
        for(int i = 0; i<a; i++){
            if(fresh[i]>b){
                totalCost = totalCost + cost[i];
            }
        }

        System.out.println(totalCost);


    }
}
