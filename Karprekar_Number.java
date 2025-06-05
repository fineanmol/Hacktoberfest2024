import java.util.*;
class Karprekar_Number
{
    void main()
    {
        Scanner rc = new Scanner(System.in);
        System.out.println("Enter a limit to print Karprekar Number");
        int n = rc.nextInt();
        System.out.println("1");
        for(int i =2;i<n;i++)
        {
            if(isKarprekar(i)==true)
            System.out.println(i);
        }
    }
    boolean isKarprekar(int n)
    {
        int sqr = n*n;
        String num = Integer.toString(sqr);
        int c = num.length();
        int firstPart = 0, secondPart = 0, sum;
        for(int i=c-1; i>0; i--) 
        {
            firstPart = sqr / (int)Math.pow(10, i);
            secondPart = sqr % (int)Math.pow(10, i);
            if(firstPart == 0 || secondPart == 0)
            continue;
            sum = firstPart + secondPart;
            if( sum == n )
            return true;
        }
        return false;
    }
}
