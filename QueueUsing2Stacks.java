import java.util.*;
class QueueUsing2stacks{
Stack<Object> s1= new Stack<>();
Stack<Object> s2= new Stack<>();
public boolean IsEmpty() {
    return s1.isEmpty();
}
public void enqueue(Object data) {
    while(!s1.isEmpty()){
        s2.push(s1.pop());
    }
    s1.push(data);
    while(!s2.isEmpty()){
        s1.push(s2.pop());
    }
}
public Object dequeue() {
    if(s1.isEmpty()){
        System.out.println("Empty queue");
        return -1;
    }
    return  s1.pop();
   
}
public Object peek() {
    if(s1.isEmpty()){
        System.out.println("Empty queue");
        return -1;
    }
    return  s1.peek();
   
}

public static void main(String[] args) {
    QueueUsing2stacks q1=new QueueUsing2stacks();
    q1.enqueue("w");
    q1.enqueue("4");
    q1.enqueue("j");
    q1.enqueue("1");
   
   
   while(!q1.IsEmpty()){
    System.out.println(  q1.peek());
  q1.dequeue();
   } 
    
 }
}

