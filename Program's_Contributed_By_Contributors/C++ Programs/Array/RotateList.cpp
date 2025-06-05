class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmp=head,*lst=head;
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        int len=0,t;
        //finding length of list
        while(tmp!=NULL){
            tmp=tmp->next;
            len++;
            //store last node of list
            if(tmp!=NULL&&tmp->next==NULL)
                lst=tmp;
        }
        //bounding number of rotations within length of list
        k=k%len;
        t=len-k;
        tmp=head;
        //traversing till desired node
        while(t>1){
            tmp=tmp->next;
            t--;
        }
        //exchange addresses
        lst->next=head;
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
};
