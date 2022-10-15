## Java program to find nth ugly number

class UglyNo {

	/*This function divides a by greatest
	divisible power of b*/
	static int maxDivide(int a, int b)
	{
		while (a % b == 0)
			a = a / b;
		return a;
	}

	/* Function to check if a number
	is ugly or not */
	static int isUgly(int no)
	{
		no = maxDivide(no, 2);
		no = maxDivide(no, 3);
		no = maxDivide(no, 5);

		return (no == 1) ? 1 : 0;
	}

	/* Function to get the nth ugly
	number*/
	static int getNthUglyNo(int n)
	{
		int i = 1;

		// ugly number count
		int count = 1;

		// check for all integers
		// until count becomes n
		while (n > count) {
			i++;
			if (isUgly(i) == 1)
				count++;
		}
		return i;
	}

	/* Driver Code*/
	public static void main(String args[])
	{
		int no = getNthUglyNo(150);
		
		// Function call
		System.out.println("150th ugly "
						+ "no. is " + no);
	}
}

