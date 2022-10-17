//Remove loop in Linked List
void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
               break;
            }
        }
             if(slow != fast){
               return ;
            }
           
           
         slow = head;
         
         while(slow != fast){
             slow = slow->next;
             fast = fast->next;
         }
         Node* temp = slow;
         while(fast->next != temp){
             fast = fast->next;
         }
        fast->next = NULL;
    }
