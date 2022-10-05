/*

Question : Balanced Brackets

1. You are given a string exp representing an expression.
2. You are required to check if the expression is balanced i.e. closing brackets and opening brackets match up well.

e.g.
[(a + b) + {(c + d) * (e / f)}] -> true
[(a + b) + {(c + d) * (e / f)]} -> false
[(a + b) + {(c + d) * (e / f)} -> false
([(a + b) + {(c + d) * (e / f)}] -> false
 
*/
 
//Code
import java.io.*;
import java.util.*;
public class Balancedbrackets
{
	public static void main(String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
	    String str = sc.nextLine();
	    Stack<Character> st = new Stack<>();
	    for(int i=0;i<str.length();i++)
	    {
	        char ch = str.charAt(i);
	        if(ch == '(' || ch == '[' || ch=='{')
	        {
	            st.push(ch);
	        }
	        else if(ch==')')
	        {
	            boolean val = handleClossing(st, '(');
	            if(val==false)
	            {
	                System.out.println(val);
	                return;
	            }
	        }
	            else if(ch=='}')
	            {
	               boolean val = handleClossing(st, '{');
	               if(val==false)
	               {
	                    System.out.println(val);
	                    return;
	                }
	            }
	            else if(ch==']')
	            {
	               boolean val = handleClossing(st, '[');
	               if(val==false)
	               {
	                    System.out.println(val);
	                    return;
	                }
	            }
	            else{
	                
	            }
	    }
	    if(st.size() == 0)
	    {
	        System.out.println(true);
	    }
	    else{
	        System.out.println(false);
	    }
	}
	    public static boolean handleClossing(Stack<Character>st, char corresoch)
	    {
	        if(st.size() == 0)
	        {
	            return false;
	        }
	        else if(st.peek() != corresoch)
	        {
	            return false;
	        }
	        else{
	            st.pop();
	            return true;
	        }
	    }
	}
