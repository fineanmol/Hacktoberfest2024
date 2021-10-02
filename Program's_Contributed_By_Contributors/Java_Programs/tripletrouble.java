//Coded by shreeyachatzz
/* We'll say that a "triple" in a string is a char appearing three times in a row. Return the number of triples in the given string. The triples may overlap.countTriple("abcXXXabc") → 1 
{countTriple("xxxabyyyycd") → 3 countTriple("a") → 0 }Solve the problem with non recursive way*/
import java.util.*;
public class Q9
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner (System.in);
        System.out.println("Enter your String");
        String st= sc.nextLine();
        int b= st.length();
        char ch,cha;
        int triple=0;
        for(int i=0; i<b; i++)//nested loop
        {
            cha= st.charAt(i);//stores the character in the 'i'th position
            int f=0;int k=0;//initialising the vlaues for k and f
            for(int j=i+1; j<b ; j++)//inner loop of the nested loop
            {
                ch=st.charAt(j);//extracts the character in the 'j'th position
                if(k<2)
                {
                    if(ch==cha)//if charasters in the 'i'th and the 'j'th positions are the same
                    {
                        f++;//updating f
                    }
                    k++;//updating k
                }
            }
            if(f>=2)
            {
                triple++;//in the case of occurance of three charaters consequtively (the number of triples are recorded
            }
        }
        System.out.println("The number of triples in the entered String are: "+triple);//To give the number of triples in the string as output

    }

    
}
/*OUTPUT:
(1)
Enter your String
xxxabyyyycd
The number of triples in the entered String are: 3

OUTPUT(2):
Enter your String
abcXXXabc
The number of triples in the entered String are: 1

OUTPUT(3):
Enter your String
a
The number of triples in the entered String are: 0
*/

        
