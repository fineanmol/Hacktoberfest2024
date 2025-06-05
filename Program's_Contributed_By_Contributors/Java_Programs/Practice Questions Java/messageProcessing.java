package eteQuestionBank;
import java.util.*;
public class messageProcessing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String res = "";
        String[] strArr = str.split(" ");

        for(int i = 0; i<strArr.length; i++){
            res = res + strArr[i];
        }

        String finalStr = res.substring(0, 1).toUpperCase() + res.substring(1);

        System.out.println(finalStr);
    }
}
