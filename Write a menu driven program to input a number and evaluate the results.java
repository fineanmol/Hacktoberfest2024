import java.util.*;
public class Disp1050
{
 public static void main()
 {
 int choice,x,i,r,fac=1;
 Scanner sc=new Scanner(System.in);
 System.out.println("Enter a number");
 x=sc.nextInt();
 System.out.print("Enter your choice:");
 choice=sc.nextInt();
 switch(choice){
 case 0:
 if(x<0){
 r=(-1)*x;
 }
 else{
 r=x;
 }
 System.out.println("Absolute value of "+x+" is "+r);
 break;
 case 1:
 for(i=1;i<=x;i++){
 fac=fac*i;
 }
 System.out.println("Factorial value of "+x+" is "+fac);
 break;
 case 2:
 System.out.println("Natural logarithm value of "+x+" is "+Math.log(x));
 break;
 case 3:
 System.out.println("Square value of "+x+" is "+x*x);
 break;
 case 4:
 System.out.println("Cube value of "+x+" is "+x*x*x);
 break;
 default:
 System.out.println("Wrong entry");
 }

 }
}
