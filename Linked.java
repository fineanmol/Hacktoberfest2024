import java.util.LinkedList;
public class Linked{   
    
    public static Node moveToFront(Node head) {
      
       if(head.next==null) return head;
       Node temp=head;
       while(temp.next.next!=null){
           temp=temp.next;
       }
       Node last=temp.next;
       temp.next=null;
       last.next=head;
       return last;
    }
    public static void main(String args[])
    {
        LinkedList llist = new LinkedList();
        
        llist.push(5);
        llist.push(4);
        llist.push(3);
        llist.push(2);
        llist.push(1);
        System.out.print(moveToFront(llist));
    }
 }