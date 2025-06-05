import java.util.*;
import java.math.*;
import java.text.*;

// 1/pi= 2root2/9801 k=0 till infinity (4k)!(1103+26390k)/k!^4*396^4k  where k=i;
class pi
{
    static int odd=1;
    public static void main()
    {
        System.out.println("Calculating PI..");
        calc();
    }

    public static void calc()
    {
        BigInteger f1;
        BigInteger f2;
        BigInteger fm;
        BigInteger fe;
        BigInteger se;
        int n=1103;
        BigInteger fa;
        BigDecimal currentPi=BigDecimal.ZERO;
        BigDecimal pi=BigDecimal.ONE;
        BigDecimal one=BigDecimal.ONE;
        int n2=2;
        double n3=Math.sqrt(2.0);
        int n4=9801;
        BigDecimal prefix=BigDecimal.ONE;
        DateFormat df=new SimpleDateFormat("MM/dd/yy HH:mm:ss");
        for(int i=0;i<1000;i++)
        {
            f1=fact(4*i);
            f2=fact(i);
            fm=BigInteger.valueOf(26390*i);
            fe=exp(f2,4);
            se=exp(BigInteger.valueOf(396),4*i);
            fa=BigInteger.valueOf(n).add(fm);
            currentPi=currentPi.add(new BigDecimal(f1.multiply(fa)).divide(new BigDecimal(fe.multiply(se)),new MathContext(100000)));
            Date date=new Date();
            System.out.println("Iteration: "+i+" at "+df.format(date));
        }

        prefix=new BigDecimal(n2*n3);
        prefix=prefix.divide(new BigDecimal(n4),new MathContext(1000));

        currentPi=currentPi.multiply(prefix, new MathContext(1000));
        pi=one.divide(currentPi,new MathContext(1000));
        System.out.println("PI is: "+pi);
        //return;
    }

    public static BigInteger fact(int a)
    {
        BigInteger result=new BigInteger("1");
        BigInteger smallRes=new BigInteger("1");
        long x=a;
        if(x==1)
            return smallRes;
        while(x>1)
        {
            result=result.multiply(BigInteger.valueOf(x));
            x--;
        }
        return result;
    }
    
    public static BigInteger exp(BigInteger a,int b)
    {
        BigInteger answer=new BigInteger("1");
        
        for(int i=0;i<b;i++)
        {
            answer=answer.multiply(a);
        }
        return answer;
    }
}