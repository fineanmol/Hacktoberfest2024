
//coded by shreeyachatzz
//Accept a string. All consonants are moved one charcter backward and all vowels are moved one character forward.
import java.util.*;
public class YARN
{
    String ys;
    String alphaacap="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String consscap="BCDFGHJKLMNPQRSTVWXYZ";
    String vowwcap="AEIOU";    
    YARN()
    {
        ys="";    
    }
    void accept()
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the String which needs to be changed");
        ys= sc.nextLine();
        ys=ys.toUpperCase();
    }
    String fnMake()
    {
        int l=ys.length();
        char p;
        String stt="";
        for(int i=0;i<l;i++)
        {
            p=ys.charAt(i);
            if(((consscap.indexOf(p))==-1))
            {
                if(((int)p>=65)&&((int)p<=90))
                {
                    stt=stt+alphaacap.charAt(alphaacap.indexOf(p)+1);
                }                
            }
            else if((vowwcap.indexOf(p)==-1))
            {
                if(((int)p>=65)&&((int)p<=90))
                {
                    stt=stt+alphaacap.charAt(alphaacap.indexOf(p)-1);                                
                }
            }
            if(p==' ')
            {
                stt=stt+" ";
            }
        }
        return(stt);
    }
    void fnshow()
    {
        System.out.println("The Strings are as follows:\nOriginal String: "+ys+"\nNew String: "+fnMake());
    }
    public static void main(String args[])
    {
        YARN ob= new YARN();
        ob.accept();
        ob.fnshow();
    }
}
//OUTPUT
/*
(1)
Enter the String which needs to be changed
ALL ZEBRAS ARE STRIPED
The Strings are as follows:
Original String: ALL ZEBRAS ARE STRIPED
New String: BKK YFAQBR BQF RSQJOFC

(2)
Enter the String which needs to be changed
all zebras
The Strings are as follows:
Original String: ALL ZEBRAS
New String: BKK YFAQBR

*/
