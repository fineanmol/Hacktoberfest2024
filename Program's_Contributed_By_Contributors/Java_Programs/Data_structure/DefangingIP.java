// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".
import java.util.*;
public class DefangingIP {
    public static String defangIPaddr(String address) {
        StringBuffer sb = new StringBuffer();
        for(int i=0;i< address.length();i++)
        {
            if(address.charAt(i) == '.' )
            {
            sb.append('[');
            sb.append(address.charAt(i));
            sb.append(']');
            }
            else
            {
            sb.append(address.charAt(i));
            }
        }
        String s = sb.toString();
        return s;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        sc.close();
        String s = sc.nextLine();
        System.out.println(defangIPaddr(s));
    }
    
}
