import java.io.*;
class magicno&palindromeno
{
public static void main(String args[])throws Exception
{
int num,choice,n,rem=0,s=0,s1=0,rem2=0,m=0,s2=0,rem3=0,reverse=0,remainder;
BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
System.out.println(“enter a number : “);
num = Integer.parseInt(in.readLine()); // Accept a number from user to check if it is a magic number or not
n=num;
System.out.println(“press 1 to check Magic number \n 2 to check Palindrome number : “);
choice = Integer.parseInt(in.readLine());

switch(choice)
{
case 1: while(n>0)
{
rem=n%10;
s=s+rem;
n=n/10;
}
while(s>0)
{
rem2=s%10;
s1=s1+rem2;
s=s/10;
}
while(s1>0)
{
rem3=s1%10;
s2=s2+rem3;
s1=s1/10;
}
if(s1==1||s2==1)
{
System.out.println(“MAgic no.”);
}
else
{
System.out.println(“Normal”);
}
break;

case 2: while(num > 0)
{
remainder = num % 10;
reverse = reverse * 10 + remainder;
num = num / 10;
}
if(reverse == n)
System.out.println(n+” is a Palindrome Number”);
else
System.out.println(n+” is not a Palindrome Number”);
break;

default : System.out.println(“Invalid Choice”);
break;
}
}
}
