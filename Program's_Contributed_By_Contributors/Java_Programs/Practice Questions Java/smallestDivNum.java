package eteQuestionBank;
import java.util.*;

public class smallestDivNum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b;
        a = sc.nextInt();
        b = sc.nextInt();

        int lcm;

        if(a>b){
            lcm = a;
        }
        else{
            lcm = b;
        }

        while(true){
            if(lcm % a == 0 && lcm % b == 0){
                System.out.println(lcm);
                break;
            }
            lcm++;
        }
    }
}
