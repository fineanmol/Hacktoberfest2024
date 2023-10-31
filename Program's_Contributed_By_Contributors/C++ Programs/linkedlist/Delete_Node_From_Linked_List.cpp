
    Node* deleteNode(Node *head, int pos)
    {
        
        if(pos == 1){
            Node* temp = head;
            head = head->next;
            
            delete temp;
            
            return head;
        }
        
        Node* temp= head;
        pos = pos-1;
        
        
        while(pos--){
            temp = temp->next;
        }


        if(temp->next == NULL){
            Node* copy = temp;
            temp->prev->next = NULL;
            delete copy;
            
            return head;
        }        
        
        
        Node* copy = temp;
        
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        
        delete copy;
        
        return head;
        
        
        
        
        
    }
