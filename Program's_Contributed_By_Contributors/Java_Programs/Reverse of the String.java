import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the string to be reversed");
		String s=sc.next();
		char ch;
		String s1="";
		for(int i=s.length()-1;i>=0;i--)
		{
		    ch=s.charAt(i);
		    s1=s1+ch;
		}
		System.out.println("Reversed String is "+s1);
	}
}
