import java.util.*;
import java.lang.Math.*;
public class Euler_phi {
	

	static int phi_sqrt(int n)
	{
		int i,res=n;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				while(n%i==0)
				{
				   n/=i;
				}
				res*=(1.0-(1.0/(float)i));
				
			}
		}
		if(n>1)
		{
			res*=(1.0-(1.0/(float)n));
		}
		return res;
	}
	static int phi3(int n)
	{
		int i,res=n,j;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				while(n%i==0)
				{
					n/=i;
					
				}
				res-=res/i;
			}
		}
		if(n>=1)
		{
			
			res-=res/n;
			
		}
		return res;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int num;
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a number: ");
		num=sc.nextInt();

		System.out.println(phi3(num));

	}

}
