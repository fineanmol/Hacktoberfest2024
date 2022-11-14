

public class LinkedListImplementation {
    Node head;
    private int size;
    class Node {
        String data;
        Node next;

        // constructor for creating node
        Node(String data) {
            this.data = data;
            this.next = null;
            size++;
        }
    }

    // For adding element in from the starting
    public void addFirst(String data) {
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        newNode.next=head;
        head=newNode;
    }
    //For adding element in from the ending
    public void addLast(String data){
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        Node curNode=head;
        while (curNode.next!=null) {
            curNode=curNode.next;
        }
        curNode.next=newNode;
    }
    //printing the elements of the list
    public void printList(){
        if(head==null){
            System.out.println("List is empty.");
            return;
        }
        Node curNode=head;
        while (curNode!=null) {
            System.out.print(curNode.data+" -> ");
            curNode=curNode.next;
        }
        System.out.print(" Null \n");

    }
    //delete element from first
    public void deleteFirst(){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        size--;
        System.out.println("Deleted '"+head.data+"'");
        head=head.next;
    }
    //delete element from last
    public void deleteLast(){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        size--;
        if(head.next==null){
            head=null;
            return;
        }
        Node secondLastNode=head;
        Node lastNode=head;
        while(lastNode.next!=null){
            lastNode=lastNode.next;
            secondLastNode=secondLastNode.next;
        }
        System.out.println("Deleted '"+secondLastNode.data+"'");
        secondLastNode.next=null;
    }
    // to get the size of the list
    public int getSize(){
        return size;
    }
    public static void main(String[] args) {

        // for checking the implementation.
     LinkedListImplementation list=new LinkedListImplementation();

        // adding,deleting and printing the elements and size.
        list.addFirst("a");
        list.addFirst("is");
        list.printList();
        System.out.println(list.getSize());


        list.addLast("list");
        list.addFirst("this");
        list.printList();
        System.out.println(list.getSize());

        list.deleteFirst();
        System.out.println(list.getSize());

        list.deleteLast();
        System.out.println(list.getSize());
    }
}
