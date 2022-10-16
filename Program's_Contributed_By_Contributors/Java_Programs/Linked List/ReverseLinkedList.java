class ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        ListNode prev=null,curr = head;
        
        while(curr!=null){
            ListNode nbr = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nbr;
        }
        
        head = prev;
        return head;
        
    }
}
