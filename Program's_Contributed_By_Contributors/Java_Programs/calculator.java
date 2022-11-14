import java.util.Scanner;

class calculator
{
	public static void main(String args[])
	{
		Scanner inpt = new Scanner(System.in);
		System.out.println("CALCULATOR");
		System.out.print("Which operation do you want to operate :");
		char operat= inpt.next().charAt(0);
		System.out.print("Inter Your First Number :");
		int num1 = inpt.nextInt();
		System.out.print("Inter Your Second Number :");
		int num2 = inpt.nextInt();
		int res;
		switch(operat)
		{
			case '+' :
			res=num1 + num2;
			System.out.println("Result : " + res);
			break;
			case '-' :
			res=num1 - num2;
			System.out.println("Result : " + res);
			break;			
			case '*' :
			res=num1 * num2;
			System.out.println("Result : " + res);
			break;				
			case '/' :
			res=num1 / num2;
			System.out.println("Result : " + res);
			break;			
			default : System.out.println("Invalid Operator !");
		}
	}
}
