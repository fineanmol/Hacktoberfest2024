// Count the number of linked list 
int getCount(struct Node* head){
 
        int cnt=0;
      Node *curr = head;
      while(curr != NULL){
          cnt++;
          curr = curr->next;
      }
      return cnt;
    }
