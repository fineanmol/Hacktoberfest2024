import java.util.*;
import java.lang.*;
import java.io.*;

public class WaterBill
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int total;
    if(n<=100){
      total = n*15;
      System.out.println(total);
    }if(n>=101 && n<=200){
      total =  100*15+(n-100)*14;
       System.out.println(total);
    }if(n>=201){
      total = 100*15+100*14+(n-200)*12;
       System.out.println(total);
    }
	}
}
