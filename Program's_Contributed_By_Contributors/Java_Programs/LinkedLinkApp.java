package packageDA;

//හැම node එකක්ම node class එකේ object එකක්. 
//Head එකක් ඕනෙ පලවෙනි නෝඩ් එක හොයාගන්න 
//Head පලවෙනි නෝඩ් එකේ ඔබ්ජෙක්ට් රෙෆෙරෙනස් එක. 
//නෝඩ් ක්ලාස් එකේ දේවල් දෙකයි. 
//එකක් තමන්ගෙ ඩේට එක තියාගන්න int data;  --> අනික,
//හැම නෝඩ් එකක්ම එකම ටයිප් එකේ ඔබ්ජෙක්ට් එකකට රෙෆරන්ස් එකක් තියාගන්නව. Node next; 
public class LinkedListApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
//-------------------------------------
//Node class
class Node {
	 int data;
	 Node next;
	 
//constructor of node class
	 Node(int item) {
		 this.data=item;
		 this.next=null;
	 }
	 
//Display the node data
	 void displayNode() {
	  System.out.print(this.data + " ");
	 } 
	}
//------------------------------------------

// LinkedList Class
	class LinkList {
		
	 private Node head;

//constructor
	 public void LinkList() {
	 head = null;
	 }
	 
	 
	 public boolean isEmpty() {
		 return (this.head==null); 
	 }
	 
// Add new node --> mulatamai new node set wenne. 
//mechchara welaa head eke thibba value eka wenas wennna one aluth node eke object reference eka widihata.
//aluth node ekee next variable ekata mechchara wela head eke thibba fereference eka ganna one.
// ehemai aluth node eka link karanne
	 public void insertFirst(int i) {
		// create new node. Node(i) kiyla dena i value eka Constructor ekata gihin data kiyana ekata add wenawa 
		 Node newNode = new Node(i);
		 newNode.next =head;
		 head = newNode;
	 
	 }
	 
// palaweni eka delete karanawa kiyanne head eka dewani node eke object referrence eka widihata set karanwa. ethakota palaweni node eka unlink wenawa.
// aluth head eka wenne danata thiyana head eke next eka. Head = Head.next	 	 
//delete krapu eka return krl pennanna nam ek issell temp ekk dagnn one delete krnn klin	
	 public Node deleteFirst() {
		 if(isEmpty()) {
			 System.out.println("List is Empty , Nothing to delete");
		 }
		 Node temp = head;
		 head = head.next;
		 temp.next = null;
		 return temp;
	 
	 }
	 
	 public void displayList() {
		 if(isEmpty()) {
			 System.out.println("List is empty, Nothing to diplay");
		 }
		 Node current = head;
		 while(current != null) {
			 current.displayNode();
			 current = current.next;
		 }
		 System.out.println();
	 }
	 
	 
	 public Node find(int key) {
		 Node current =head;
		 int count =1;
		 while(current!=null) {
			 if(count==key) {
				 return current;
				 
			 }
			 current =current.next;
			 count++;
		 }
		 System.out.println("Item not Found");
		 return null;
	 }
	 
	 public void delete(int key) {
	        
	        Node curr = this.head;
	        Node prev = this.head;
	        int count = 1;
	        
	        while(curr!=null){
	            
	            if(count == key){
	                if(count == 1){
	                    this.deleteFirst();
	                }else{
	                    prev.next = curr.next;
	                    curr.next = null;
	                }
	            }
	            
	            prev = curr;
	            curr = curr.next;
	            count++;
	        }
	 
	 }
	 
} 
	 
	 
	 
