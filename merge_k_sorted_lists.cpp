ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode * head=new ListNode(0);
        ListNode * it=head;
        while(true)
        {
            bool found=false;
            ListNode * mini=NULL;
            int ind=-1;
            int ans;
        for(auto i: lists)
        {
            ind++;
            ListNode*tmp=i;
            if(!i) continue;
            found=true;
            if(!mini){ mini=tmp; ans=ind;}
            else if(mini->val>tmp->val) {mini=tmp; ans=ind;}
            
        }
            if(!found) break;
            it->next=mini;
            it=it->next;
            lists[ans]=lists[ans]->next; 
        }
        return head->next;
    }
int main()
{
  
}
