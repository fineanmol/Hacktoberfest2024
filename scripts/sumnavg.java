import java.util.Scanner;


class sumnavg
{
	public static void main(String args[])
	{
		int a,b,c,sum,average;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the First Number : ");
		a = sc.nextInt();
		System.out.println("Enter the Second Number : ");
		b = sc.nextInt();
		System.out.println("Enter the Third Number : ");
		c = sc.nextInt();
		System.out.println("Sum of 3 Numbers     : "+(a+b+c)+"\n"+"Average of 3 Numbers : "+((a+b+c)/3));
		
	} 

}
