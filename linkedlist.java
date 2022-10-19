package com.linkedlist;

public class LinkedList {
  private Node head;
  
  public LinkedList() {
	  this.head=null;
  }
  
  public Node insertAtHead(int data) {
	  Node node= new Node(data);
	  if(head==null) {
		  head=node;
		
	  }
	  else {
		  node.next=head;
		  head=node;
	  }
	  return head;
  } 
  public Node insertAtEnd(int data) {
	  Node node=new Node(data);
	  
	  Node n=head;
	  if(head==null) {
		  insertAtHead(data);
	  }
	  else {
	  while(n.next!=null) {
		  n=n.next;
	  }
	  n.next=node; }
	  return node;
  }
  
  public void print () {
	  Node temp=head;
	  while (temp!=null) {
		  System.out.print(temp.data+" -> ");
		  temp=temp.next;
	  }
  }
  //Iterative Approach
  public int printLength() {
	Node temp=head; 
	if (head==null) {
		return 0;
	}
	int count=0;
	while (temp!=null) {
		 
		  temp=temp.next;
		  count++;
	  }
	return count;
  }
  //Recursive APPROACH
  public int printlengthr(Node node) {
	  if(node==null) {
		  return 0;
	  }
	  else {
		  return 1+printlengthr(node.next);
	  }
	  
  }
  public int printmiddle() {
	  Node run= head;
	  Node walk=head;
	  
	  while (run!=null && run.next!=null) {
		  run=run.next.next;
		  walk=walk.next;
	  }
	  
	  return walk.data;
  }
  
  public boolean search(int data) {
	  Node temp=head;
	  while (temp!=null ) {
		  if (temp.data==data) {return true;}
		  temp=temp.next;
	  }
	  return false;
  }
  public boolean recursiveSearch(int value,Node node) {
	  if (node==null) {
		  return false;
	  }
	  if (node.data==value) {
		  return true;
	  }
	  return recursiveSearch(value, node.next);
  }
  
  public void sort() {
	  int counter[]= {0,0,0};
	  Node temp=head;
	  while (temp!=null) {
		  counter[temp.data]++;
		  temp=temp.next;
	  }
	  
	  temp =head;
	  int i=0;
	  while(temp!=null) {
		  if (counter[i]==0)  {i++;}
		  else {temp.data=i;
		  counter[i]--;
		System.out.println(temp.data);
		 temp=temp.next;
		  }
		 
		 
	  }
  }
  public void  reverse() {
	  
	 Node previous = null;
	 Node temp= null;
	 Node next= head;
	
	 
	 while (next!=null ) {
		temp=next.next;
		next.next=previous;
		previous=next;
		next=temp;
	
		
	 }
	 head.next=temp;
	// return previous;
  }
  
  
  public static void main(String[] args) {
	LinkedList list= new LinkedList();
//	LinkedList listsort= new LinkedList();
	
	
	list.insertAtHead(5);
	list.insertAtHead(6);
	list.insertAtHead(8);
	list.insertAtEnd(10);
	list.insertAtEnd(11);
	list.insertAtEnd(12);
//	
//	listsort.insertAtHead(2);
//	listsort.insertAtHead(1);
//	listsort.insertAtHead(0);
//	listsort.insertAtHead(0);
//	listsort.insertAtHead(1);
//	listsort.insertAtHead(2);
//	listsort.insertAtHead(1);
	
	list.print();
	System.out.println();
//	list.sort();
	list.reverse();
	//System.out.println(list.reverse());
	list.print();
//	listsort.sort();
//	listsort.print();
//	//System.out.println(list.printLength());
//	System.out.println("END");
//	System.out.println(list.printmiddle());
//	System.out.println(list.search(100));
//	System.out.println(list.recursiveSearch(6, list.head));
}
  
  
}
