package eteQuestionBank;
import java.util.*;
public class makeEqual {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int[] arr = new int[n];

        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        if(ifEqual(arr)){
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }
    }

    static boolean ifEqual(int[] arr){
        for(int i = 0; i<arr.length; i++){
            while(arr[i]%2==0){
                arr[i] = arr[i]/2;
            }
            while(arr[i]%3==0){
                arr[i] = arr[i]/3;
            }
        }

        for(int i = 1; i< arr.length; i++){
            if(arr[i]!=arr[0]){
                return false;
            }
        }

        return true;
    }
}
