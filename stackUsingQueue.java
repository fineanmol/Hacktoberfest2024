import java.util.*;
import java.lang.*;
import java.io.*;


class MyStack{
        Queue<Integer> q = new LinkedList<>();
        void push(int val){
                q.offer(val);
                // poll all elements and offer to queue except the current one
                for(int i = 0; i < q.size() - 1; i++){
                        q.offer(q.poll());
                }
        }
        void pop(){
                if(!q.isEmpty())
                System.out.print(q.poll() + " ");
                else System.out.print(-1 + " ");
        }
}
public class Main
{
	public static void main (String[] args) throws java.lang.Exception{
                Scanner sc = new Scanner(System.in);
                int q = sc.nextInt();
                MyStack st = new MyStack();
                for(int i = 0; i < q; i++){
                        if(sc.nextInt() == 1){
                                st.push(sc.nextInt());
                        }
                        else {
                                st.pop();
                        }
                }
                System.out.println();
        }
}

