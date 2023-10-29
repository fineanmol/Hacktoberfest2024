package eteQuestionBank;
import java.util.*;
public class productTag {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String product = sc.next();

        StringBuilder sb = new StringBuilder();

        int len = product.length();


        for(int i = 0; i<len-1; i=i+2){
            if(product.charAt(i)>product.charAt(i+1)){
                sb.append(product.charAt(i));
            }
            else{
                sb.append(product.charAt(i+1));
            }
        }
        if(len%2!=0){
            sb.append(product.charAt(len-1));
        }

        System.out.println(sb);

    }
}
