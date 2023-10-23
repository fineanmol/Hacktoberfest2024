import java.util.*;
import java.lang.String;
class Main 
{
    public static String capitalize(String str) 
  {
        if (str == null || str.isEmpty())
        {
            return str;
        }
        return str.substring(0, 1).toUpperCase() + str.substring(1);
   }
   public static void main(String[] args) 
  {
        Scanner sc = new Scanner(System.in);
        String finStr = "";
        System.out.print("\nEnter the String: ");
        String str = "" + sc.nextLine();
        String[] stra = str.split(" ");
        for(String a: stra) 
        {
            finStr = finStr.concat(capitalize(a));
            finStr = finStr.concat(" ");
        }
        System.out.print("Capitalized String: ");
        System.out.println(finStr);
        System.out.print("\n");
  }
}  
  
  
  
