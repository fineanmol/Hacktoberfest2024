import java.util.*;
class automorphic
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n,m,n1,c=0,d,x,y=0,d1,d2;
        System.out.println("Enter a number");
        n=sc.nextInt();
        n1=n;
        System.out.println("Square of number is");
        m=n*n;
        System.out.println(m);
        while(n1>0)
        {
            d=n1%10;
            c++;
            n1/=10;
        }
        x=c;
        while(x!=0)
        {
            d1=n%10;
            d2=m%10;
            x--;
            n/=10;
            m/=10;
            if(d1==d2)
            y++;
        }
        if(y==c)
        System.out.println("Automorphic number");
        else
        System.out.println("Not a automorphic number");
    }
}
            
            