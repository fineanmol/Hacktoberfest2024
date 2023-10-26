import java.util.Scanner;
public class Main{
    static void table (int num){
        for (int i=1;i<=10;i++){
            System.out.print(num+"x"+i+"= ");
            sqr();
            sqr((num*i));
            sqr(2.0f);
        }
    }
    static void sqr(int num){   
        System.out.println("Square of number is: "+(num*num));
    }
    
    static void sqr(){
        System.out.println("Square of number is: "+(4*2));
    } 
    static void sqr(float num){
        System.out.println("Square of number is: "+(num*num));
    }
    
    
    public static void main(String args[]){
       table(2);
       sqr(2);
     }
}




/* Output 
2x1= Square of number is: 8
Square of number is: 4
Square of number is: 4.0
2x2= Square of number is: 8
Square of number is: 16
Square of number is: 4.0
2x3= Square of number is: 8
Square of number is: 36
Square of number is: 4.0
2x4= Square of number is: 8
Square of number is: 64
Square of number is: 4.0
2x5= Square of number is: 8
Square of number is: 100
Square of number is: 4.0
2x6= Square of number is: 8
Square of number is: 144
Square of number is: 4.0
2x7= Square of number is: 8
Square of number is: 196
Square of number is: 4.0
2x8= Square of number is: 8
Square of number is: 256
Square of number is: 4.0
2x9= Square of number is: 8
Square of number is: 324
Square of number is: 4.0
2x10= Square of number is: 8
Square of number is: 400
Square of number is: 4.0
Square of number is: 4
 */
