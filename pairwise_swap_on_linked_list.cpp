//Pairwise swap of nodes in LinkedList
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    Node* curr = head;
    while(curr!= NULL && curr->next  != NULL){
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
    return head;
}
