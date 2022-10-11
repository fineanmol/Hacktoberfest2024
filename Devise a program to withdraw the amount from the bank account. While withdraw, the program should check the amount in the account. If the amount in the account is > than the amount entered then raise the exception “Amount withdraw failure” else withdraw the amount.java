import java. util.*;
public class Withdraw1050 {
 public static void main(String[] args){
 Scanner sc = new Scanner (System.in);
 System.out.println("Enter the Amount Present in your Account: ");
 int a = sc.nextInt();
 System.out.println("Enter the Amount you want to withdraw: ");
 int b = sc.nextInt();
 try{
 if (b<a){
 System. out. println((a-b)+" is left in your Account.");

 }else {
 throw new Exception();
 }
 }
 catch(Exception e){
 System. out.println("Amount WithDraw Failure!!");
 }


 }
}
