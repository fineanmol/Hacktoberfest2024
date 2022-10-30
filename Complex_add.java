import java.util.*;

public class Complex
{



private int real1,img1,real2,img2,real3,img3;

public void getdata()
{
Scanner sc=new Scanner (System.in);
System.out.println("Enter real and imaginary part of first complex no:");
real1=sc.nextInt();
img1=sc.nextInt();
System.out.println("Enter real and imagimary part of second complex no:");
real2=sc.nextInt();
img2=sc.nextInt();
}




public void add()
{
real3=real1+real2;
img3=img1+img2;
}

public void display()
{
	System.out.println("First complex number is:");
	System.out.println(real1+"+"+img1+ "i");
	System.out.println("Second complex number is:");
	System.out.println(real2+"+"+img2+ "i");
	System.out.println("Result is:");
	System.out.println(real3+"+"+img3+ "i");
}
}

public class Complex_add {

public static void main(String[] args)
{
Complex obj=new Complex();
obj.getdata();
obj.add();
obj.display();
}

}
