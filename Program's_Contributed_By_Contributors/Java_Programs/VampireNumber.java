//Coded by shreeyachatzz
//To check if a number is a vampire no or not. If vampire then print its fangs.
import java.util.*;
class Vampire
{
    /*To check how many times each digit occurs in the number and comparing their values to make sure that the number of
    times a digit occurs in the no. is not the same as the number of times the same digit occurs in the factors taken together*/
    static int checkdigit(String num1, String num2)
    {
        for (int i=0;i<num1.length();i++)
        {
            char c1=num1.charAt(i);
            if((num1.substring(0,i).indexOf(c1))!=-1)//To check if a digit repeats itself in the substring 
            continue;
            if(num2.indexOf(c1)==-1)//To check the presence of the digit in the factors
            return 0;
            
            int f1=0;int f2 =0;
           
            for(int k=0;k<num1.length();k++)//To find how many times c1 occurs in num1
            {
                if(c1==num1.charAt(k))
                f1=f1+1;
            }
            for(int p=0;p<num2.length();p++)//To find how many times c1 occurs in num2
            {
                if(c1==num2.charAt(p))
                f2=f2+1;
            }
            if(f1!=f2)//If c1 occurs the same number of times in num1 and num2
            {
                return 0;
            }
           
        }
        return 1;
       
    }
    public static void main()//Main method
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("ENTER  A NUMBER");
        String str=sc.next();//Accepting number in string 
        int f1=0;
        int f2=0;
        int l=str.length();//To find the number of digits in the string(number)
        int n=Integer.parseInt(str);//Converting the number from string data type to integer data type
        int in=(int)(Math.pow(10,(l/2)-1));//first number to start checking factors from       
        int fn=(int)(Math.pow(10,l/2));//Last number beyond which the factors can not be searched
        System.out.println("The range of the factors:");
        System.out.println("From "+in+" to "+fn);int f=0;//Printing the range
        for(int i=in;i<fn;i++)//Finding factors
        {
            if(n%i==0)//Condition for factor
            {
                f1=i;//The factor
                f2=n/i;//The number which when multiplied by f1 gives n
                //converting the integer number to string form to check its number of digits
                if(Integer.toString(f2).length()==l/2)
                {
                    if(f1%10==0&&f2%10==0)//To check if both the numbers end with zero(0)
                    {
                        continue;
                                            }
                    else
                    {
                        String str2=f1+""+f2;//Storing the two factors in a string
                        int r= checkdigit(str, str2);
                        if(r==1)
                        {
                            f=1;
                            System.out.println(str+" "+"IT IS A VAMPIRE NUMBER \nThe fangs are: "+ f1+" and "+f2);
                            return;
                        }
                        else
                        continue;
                    }
                }
               
            }
           
        }
        if (f==0)
        {
            System.out.println(str+" "+"IT IS NOT A VAMPIRE NUMBER");
           return;
        }
    }
}
/*
(1)ENTER  A NUMBER
1827
The range of the factors:
From 10 to 100
1827 IT IS A VAMPIRE NUMBER 
The fangs are: 21 and 87
(2)ENTER  A NUMBER
1260
The range of the factors:
From 10 to 100
1260 IT IS A VAMPIRE NUMBER 
The fangs are: 21 and 60
(3)ENTER  A NUMBER
126000
The range of the factors:
From 100 to 1000
126000 IT IS NOT A VAMPIRE NUMBER
*/
