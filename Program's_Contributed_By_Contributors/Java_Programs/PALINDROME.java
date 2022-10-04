import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
		System.out.println("enter n");
		int nn=sc.nextInt();
		for(int i=1;i<=nn;i++){
		    System.out.println("Enter number");
		    int num=sc.nextInt();
		    String newnum="";
		    int n=num;
		    int d;
		    while(n!=0){
		         d=n%10;
		         n=n/10;
		         newnum = newnum+d;
		    }
		    if(num==0 || num/10==0){
		         System.out.println("not palindrome");
		    }
		    else if(Integer.valueOf(newnum) == num){
		        System.out.println("Palindrome");
		    }
		    else{
		        System.out.println("not palindrome");
		    }
		}
	}
}
