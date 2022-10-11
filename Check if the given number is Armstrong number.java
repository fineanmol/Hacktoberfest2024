import java.util.*;
public class Disp1050
{
 public static void main()
 {
 int a,arm=0;
 Scanner sc=new Scanner(System.in);
 System.out.println("Enter a number");
 int n=sc.nextInt();
 int temp=n;
 while(n!=0){
 a=n%10;
 arm=arm+(a*a*a);
 n=n/10;
 }
 if (arm==temp){
 System.out.println(temp+" is an armstrong number");
 }
 else{
 System.out.println(temp+" is not an armstrong number");
 }
 }
}
