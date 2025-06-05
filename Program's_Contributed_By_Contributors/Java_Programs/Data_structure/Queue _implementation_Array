package datastructure;
import java.util.*;

public class QueueImpArray {

	static class queue{
		static int arr[];
		static int size;
		static int rear=-1;
		
		queue(int size){
			arr=new int[size];
			this.size=size;
		}
		
		public static boolean isEmpty() {
			return rear == -1;
		}
		
		//ENQUEUE
		public static void add(int data) {
			if(rear == size-1) {
				System.out.println("Full queue");
				return;
			}
			rear++;
			arr[rear] = data;
		}
		
		//DEQUEUE
		public static int remove() {
			if(isEmpty()) {
				System.out.println("Empty Queue");
				return -1;
				}
			int front=arr[0];
			for(int i=0;i<rear;i++) {
				arr[i]=arr[i+1];
			}
			rear--;
			return front;
		}
		
		//PEEK
		public static int peek() {
			if(isEmpty()) {
				System.out.println("Empty Queue");
				return -1;
				}
		  return arr[0];
		}	
	}
	public static void main(String[] args) 
	{
		queue q=new queue(5);
		 q.add(1);
		 q.add(2);
		 q.add(3);
		 q.add(4);
		 q.add(5);
		 q.remove();
		 while(!q.isEmpty()) {
			 
			 System.out.print(q.peek() + " > ");
			 q.remove();
		 }
		 

	}

}
