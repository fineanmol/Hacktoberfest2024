package eteQuestionBank;
import java.util.*;

public class lastKthElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);



        ArrayList<Integer> arr = new ArrayList<>();

        int n = sc.nextInt();
        while(n!=-1){
            arr.add(n);
            n = sc.nextInt();
        }

        int key = sc.nextInt();

        ArrayList<Integer> res = new ArrayList<>();

        for(int i = arr.toArray().length-1; i>=0; i--){
            res.add(arr.get(i));
        }

        System.out.println(res.get(key-1));
    }
}
