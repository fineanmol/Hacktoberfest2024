import java.util.Scanner;


class rec
{
	public static void main(String args[])
	{
		int a,b,c;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length of the Rectange : ");
		a = sc.nextInt();
		System.out.println("Enter the height of the Rectange : ");
		b = sc.nextInt();
		System.out.println("The Area of the Rectange = "+(a*b)+"\n"+"The Perimeter of the Rectange = "+(2*(a+b)));
	} 

}

