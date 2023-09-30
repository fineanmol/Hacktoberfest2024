//package Program's_Contributed_By_Contributors.pattern using java;


/* 
     1 
   2 1 2 
  3 2 1 2 3 
 4 3 2 1 2 3 4 
5 4 3 2 1 2 3 4 5 
*/
import java.util.*;
public class palindrome {


    
    public static void main(String[] args) {
        int n=5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                System.out.print(" ");
            }
            for(int j=i;j>=1;j--){
                System.out.print(j + " ");
            }
            for(int j=2;j<=i;j++){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}