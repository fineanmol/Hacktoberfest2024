package eteQuestionBank;
import java.util.*;
public class setBitCount {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int res = 0;

        for(int i = 1; i<=num; i++){
            res = res + setBit(i);
        }

        System.out.println(res);

    }

    static int setBit(int n){
        ArrayList<Integer> arr = new ArrayList<>();
        while(n!=0){
            int rem = n%2;
            arr.add(rem);
            n = n/2;
        }
        int count = 0;

        for(int i = 0; i<arr.toArray().length; i++){
            if(arr.get(i)==1){
                count++;
            }
        }
        return count;
    }

}
