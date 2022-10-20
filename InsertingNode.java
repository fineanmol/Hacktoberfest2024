package linkedlist;

public class InsertingNode {
	static class LinkedList {
    static Node head;
    static class Node {
    int data;
    Node next;
    Node(int d) {
       data = d;
       next = null;
   }
}
  static Node insert (Node head ,int elem,int pos)  {
	  Node nodeToBeInserted = new Node(elem);
	  int count=0;
	  Node prev = head;
	  if(pos==0) {
		  nodeToBeInserted.next =head; 
		return nodeToBeInserted;
	  }
	  while(count<pos-1 && prev!=null) {
		  count++;
		  prev=prev.next;
	  }
	  if(prev!=null) {
	  nodeToBeInserted.next=prev.next;
	  prev.next=nodeToBeInserted;
	  }
	  return head;  
  }
  static void printList(Node node) {
      while (node != null) {
          System.out.print(node.data + " ");
          node = node.next;
      }
  }
  public static void main(String[] args) {
	  LinkedList list = new LinkedList();
      list.head = new Node(33);
      list.head.next = new Node(90);
      list.head.next.next = new Node(89);
      list.head.next.next.next = new Node(7);
      
      insert(head,777,2);
      printList(head);  

  }   
    
}
}
