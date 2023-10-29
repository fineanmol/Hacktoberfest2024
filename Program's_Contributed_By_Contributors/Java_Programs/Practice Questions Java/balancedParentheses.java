package eteQuestionBank;
import java.util.*;
public class balancedParentheses {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.next();

        if(isValid(str)){
            System.out.println("VALID");
        }
        else{
            System.out.println("NOT VALID");
        }




    }

    static boolean isValid(String str){
        Stack<Character> st = new Stack<>();
        for(int i = 0; i<str.length(); i++){
            Character ch = str.charAt(i);
            if(ch=='(' || ch=='{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.isEmpty()){
                    return false;
                }
                else {
                    int top = st.peek();
                    if(ch==')' && top=='(' || ch=='}' && top=='{' || ch==']' && top=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return (st.isEmpty());
    }
}
