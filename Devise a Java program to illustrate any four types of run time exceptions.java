public class RunTim1050
{
 public static void main(String[] args)
 {

 int n1=50;
 int n2=0;
 try
 {
 int div=n1/n2;
 System.out.println("Result of divison is: "+div);
 }
 catch(ArithmeticException e)
 {
 System.out.println("Denominator cannot be 0!");
 }
 try
 {
 String s=null;
 System.out.println(s.charAt(0));
 }
 catch(NullPointerException e)
 {
 System.out.println("Null Pointer Exception occurred");
 }
 try
 {
 String s="I am learning JAVA";
 char c=s.charAt(100);
 }
 catch(StringIndexOutOfBoundsException e)
 {
 System.out.println("String index out of bound exception occurred")
;
 }
 try
 {
 int n=Integer.parseInt("Hello World");
 System.out.println(n);
 }
 catch(NumberFormatException e)
 {
 System.out.println("Number format exception occurred");
 }

 }
}
