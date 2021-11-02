//Demonstration of super class

class Super
{
	int x;
	Super(int x)
	{
		this.x = x;
	}
	void display()
	{
		System.out.println("Super x =" +x); //print super object
	}
}
Class Sub extends Super
{
	int y;
	sub (int x, int y)
	{
		super (x);
		this.y=y;
	}
	void display()
	{
		System.out.println("Super x =" +x);
		System.out.println("Sub y =" +y);
	}
}
class OverrideTest
{
	public static void main(String args[])
	{
		Sub sl = new Sub(100,200);
		sl.display();
	}
}
