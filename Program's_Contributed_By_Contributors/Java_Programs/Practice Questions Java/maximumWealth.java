package eteQuestionBank;
import java.util.*;

public class maximumWealth {
    public static void main(String[] args) {
        int[][] accounts = {{1,2,3}, {3,2,1}};

        int max = maximumWealth(accounts);
        System.out.println(max);
    }

    static int maximumWealth(int[][] accounts) {

        int max = 0;
        for(int i = 0; i<accounts.length; i++){
            int sum = 0;
            for(int j = 0; j<accounts[i].length; j++){
                sum = sum + accounts[i][j];
                System.out.print("sum at " + j + ": " +  sum);
            }
            System.out.println();

            if(sum>max){
                max = sum;
            }
        }

        return max;

    }
}
