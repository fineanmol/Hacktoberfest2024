public class reverseList{

    ListNode reverse(ListNode head){
        ListNode prev=null;
        ListNode cur=head;
        ListNode next=null;
        while(cur!=null){
            next=cur.next;
            cur.next=prev;
            prev=cur;
        }
        return prev;
    }
    public static void main(String[] args){
        ListNode head=reverse(head1);
    }
    
}
class ListNode{
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int val){
        this.val= val;        
    }
    ListNode(int val,ListNode next){
        this.val=val;
        this.next=next;
    }
}