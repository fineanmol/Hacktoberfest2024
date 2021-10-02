class threading extends Thread
{
public void run()
{
	for(int i=0;i<=5;i++)
	{
		try
		{
			Thread.sleep(500);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.println(i);
	}
}
public static void main(String argc[])
{
	threading o1=new threading();
	threading o2=new threading();
	threading o3=new threading();
	o1.start();
	try
	{
		o1.join(1500);
	}
	catch(Exception r)
	{
		System.out.println(r);
	}
	o2.start();
	o3.start();
}
}