class Solution{
  public ListNode rotateRight(ListNode head,int k){
    if(k==0 || head==null || head.next==null){return head;}
      ListNode last=head;
  }
  int length=1;
  while(last.next!=null){
    last=last.next;
    length++;
  }
  int rot=k%length;
  int skip=length-rot;
  ListNode newEnd=head;
  for(int i=0;i<skip-1;i++){
    newEnd=newEnd.next;
  }
  head=newEnd.next;
  newEnd.next=null;
  return head;
  
}
