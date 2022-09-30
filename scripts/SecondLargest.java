import java.util.Scanner;


class SecondLargest
{
	public static void main(String args[])
	{
		int a,b,c;
		int second=0;
		a = 100; b = 20; c = 30;
		if(a>b && a>c)
		{	
			if (b>c)
			{
				second = b;
			}
			if (c>b)
			{
				second = c;
			}
		}
		else if(b>a && b>c)
		{
			if (a>c)
			{
				second = a;
			}
			if (c>a)
			{
				second = c;
			}
		}
		else
		{
			if (b>a)
			{
				second = b;
			}
			if (a>b)
			{
				second = a;
			}
		}
		System.out.println("Second Largest is "+second);
		
	} 
	

}

