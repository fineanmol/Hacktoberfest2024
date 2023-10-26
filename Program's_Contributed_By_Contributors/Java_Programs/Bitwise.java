//Bitwise  Operators
import java.util.Scanner;
public class Main
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    int a,b;
    System.out.print("enter Value of a : ");
    a=sc.nextInt();
    System.out.print("enter Value of b : ");
    b=sc.nextInt();
    System.out.println(a&b);
    System.out.println(a|b);
    System.out.println(a^b);
    System.out.println(a>>1);
    System.out.println(1<<a);
}
}

/*
enter Value of a :  5
enter Value of b :  1
1
5
4
2
32
*/
