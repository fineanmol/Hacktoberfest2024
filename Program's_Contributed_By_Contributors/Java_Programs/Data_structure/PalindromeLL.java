import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class LinkedListNode<T> {
    T data;
    LinkedListNode<T> next;
    
    public LinkedListNode(T data) {
        this.data = data;
    }
}

class Solution {
    
    public static LinkedListNode<Integer> middle(LinkedListNode<Integer> head){
        LinkedListNode<Integer> fast=head,slow=head;
        
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    
    public static LinkedListNode<Integer> reverseI(LinkedListNode<Integer> head){
        
        
        LinkedListNode<Integer>curr=head,prev=null;
        while(curr!=null){
            LinkedListNode<Integer> temp=curr.next;       
            curr.next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
        
    }
    
     public static LinkedListNode<Integer> reverseR(LinkedListNode<Integer> head){
         if(head==null || head.next==null){
             return head;
         }
         LinkedListNode<Integer> newHead=reverseR(head.next);
         LinkedListNode<Integer> headNext=head.next;
         headNext.next=head;
         head.next=null;
         return newHead;
             
         
     }

	public static boolean isPalindrome(LinkedListNode<Integer> head) {
		
        if(head==null || head.next==null){
            return true;
        }
        LinkedListNode<Integer> mid=middle(head);
        LinkedListNode<Integer> last=reverseR(mid);
        LinkedListNode<Integer> curr=head;
        
        while(curr!=null && last!=null){
            if(!(curr.data.equals(last.data))){
                return false;
            }
            curr=curr.next;
            last=last.next;
        }
        
        return true;
	}

}

public class PalindromeLL {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static LinkedListNode<Integer> takeInput() throws IOException {
        LinkedListNode<Integer> head = null, tail = null;

        String[] datas = br.readLine().trim().split("\\s");

        int i = 0;
        while(i < datas.length && !datas[i].equals("-1")) {
            int data = Integer.parseInt(datas[i]);
            LinkedListNode<Integer> newNode = new LinkedListNode<Integer>(data);
            if(head == null) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail.next = newNode;
                tail = newNode;
            }
            i += 1;
        }

        return head;
    }
    
    public static void print(LinkedListNode<Integer> head){
        while(head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        
        System.out.println();
    }
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int t = Integer.parseInt(br.readLine().trim());

        while (t > 0) {

            LinkedListNode<Integer> head = takeInput(); 

            boolean ans = Solution.isPalindrome(head);
            System.out.println(ans);

            t -= 1;

        }
        
    }
}
