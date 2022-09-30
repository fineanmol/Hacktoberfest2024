//This is a Java Program to check whether the given number is Armstrong Number or not!
class armstrong{
	
public static void main(String arg[]){
	int i = 100,arm;
	System.out.println("Armstrong numbers between 100 to 199");
	while(i<1000)
	{
		arm= armstrongOrnot( i);
		if(arm==i)
		System.out.println(i);
		i++;
	
	}
	
}
static int armstrongOrnot( int num)
{
	int x, a=0;
	while (num!=0)
	{
		x=num%10;
		a=a+ (x*x*x);
		num/=10;
	}
	return a;
}

}