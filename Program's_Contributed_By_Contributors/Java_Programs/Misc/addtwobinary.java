import java.util.*;

public class addtwobinary {
 public static void main(String args[]) 
 { 
 long b1,b2; 
 int i=0,carry=0; 
 int[] arr= new int[10]; 
 Scanner sc=new Scanner(System.in); 
 System.out.println("Enter the first binary number:"); 
 b1 = sc.nextLong(); 
 System.out.println("Enter the second binary number:"); 
 b2=sc.nextLong(); 
 sc.close(); 
 while(b1!=0 || b2!=0) 
 { 
 arr[i]=(int)((b1%10 + b2%10 + carry)%2); 
 i++; 
 carry=(int)((b1%10 + b2%10 +carry)/2); 
 b1=b1/10; 
 b2=b2/10; 
  } 
 if(carry!=0) 
 { 
 arr[i]=carry; 
 i++; 
 } 
 System.out.println("Addition of two binary numbers is :"); 
i--; 
 while(i>=0) 
 { 
 System.out.println(arr[i]); 
 i--; 
 } 
 }
}
