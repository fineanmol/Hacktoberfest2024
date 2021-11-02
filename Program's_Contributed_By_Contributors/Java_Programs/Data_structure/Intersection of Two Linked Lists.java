/*
 * To find the intersection point of two linked lists:
 * 			Using Two pointers approach:
						*Initialize two pointers "a" and "b" at the headA and headB.
						*Traverse through the lists,one node at a time.
						*When "a" reaches the end of a list, then redirect it to the headB.
						*similarly when "b" reaches the end of a list, redirect it the headA.
						*Once both of them go through reassigning, they will be equdistant from 
						 the collision point
						*If at any node "a" meets "b", then it is the intersection node.
						*After second iteration if there is no intersection node it returns NULL.
 */



/*The input is as follows:
 * line1: no of nodes in the first linked list
 * line2: enter first linked list elements
 * line3: no of nodes in the second linked list
 * line4: enter second linked list elements
 * line5: enter the no of nodes in the common linked list
 * line5: enter the elements of the common linked list
 */

/*The output is as follows:
 * line1: A message indicating the the provided linked lists are being intersected will pop up
 * line2: First Linked list after intersection
 * line3: Second Linked List after intersection
 * line4: The intersection point
 */


import java.util.*;
class SinglyLinkedList
{
	
	class ListNode
	{
	      int val;
	      ListNode next;
	      ListNode() {}
	      ListNode(int val) { this.val = val; }
	      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
	 }
	
	public ListNode head=new ListNode(0);
	public ListNode curr=head;
	
	
	public void addNode(int data)
	{
		//Function to add nodes to the respective linked lists
		ListNode node=new ListNode(0);
		node.val=data;
		curr.next=node;
		curr=curr.next;
	}
	
	
	public static void intersect(ListNode last1,ListNode last2, ListNode commonHead)
	{
		//Function to construct an intersecting linked list for the question
		last1.next=commonHead;
		last2.next=commonHead;
	}
	
	
	public void display()
	{ 
		//Function to print the linked lists if required
		ListNode temp=head.next;
		while(temp!=null)
		{
			System.out.print(temp.val+" ");
			temp=temp.next;
		}
		System.out.println();
	}
	
	
	public static int getIntersectionNode(ListNode headA, ListNode headB)
	{
		//Function to find intersection point in Y shaped Linked Lists.
		ListNode a=headA;
        ListNode b=headB;
        int c=0,d=0;
        while(a!=b)
        {
            if(a==null)
            {
                a=headB;
                c++;
            }
            else
            {
                a=a.next;
            }
            if(b==null)
            {
                b=headA;
                d++;
            }
            else
            {
                b=b.next;
            }
            if(c==2||d==2)
                return -1;
        }
        if(a==b && a!=null &&b!=null)
            return a.val;
        else
        	return -1;
    }
	
	
	public static void main(String[] args) {
		 Scanner Sc=new Scanner(System.in);
		SinglyLinkedList list1=new SinglyLinkedList();
		SinglyLinkedList list2=new SinglyLinkedList();
		SinglyLinkedList common=new SinglyLinkedList();
		int n1=Sc.nextInt();
		while(n1-->0)
			list1.addNode(Sc.nextInt());
		int n2=Sc.nextInt();
		while(n2-->0)
			list2.addNode(Sc.nextInt());
		int n3=Sc.nextInt();
		while(n3-->0)
			common.addNode(Sc.nextInt());
		System.out.println("Intersecting the lists");
		System.out.println("*****************************");
		intersect(list1.curr,list2.curr,common.head.next);
		System.out.print("First linked list: ");
		list1.display();

		System.out.print("Second linked list: ");
		list2.display();
		
		System.out.print("Intersection point: ");
		if(getIntersectionNode(list1.head.next,list2.head.next)==-1)
			System.out.println("null");
		else
			System.out.println(getIntersectionNode(list1.head.next,list2.head.next));
		Sc.close();
	}
}


/*
Sample Input 1;
1
1
2
2 3
3
4 5 6
Sample Output 1:
Intersecting the lists
*****************************
First linked list: 1 4 5 6 
Second linked list: 2 3 4 5 6 
Intersection point: 4
Sample Input 2:
	 
3
9 8 7
4
2 3 6 5
3
15 4 19
Sample Output 2:
Intersecting the lists
*****************************
First linked list: 9 8 7 15 4 19 
Second linked list: 2 3 6 5 15 4 19 
Intersection point: 15
*/



/*
Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
*/
