using namespace std;
 

struct Node {
    int data;
    struct Node* next;
    int flag;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    
    new_node->data = new_data;
    new_node->flag = 0;
 
    /* linking the old list off the new node */
    new_node->next = (*head_ref);
 
    (*head_ref) = new_node;
}
 
bool detectLoop(struct Node* h)
{
    while (h != NULL)
    {
       
        if (h->flag == 1)
            return true;
 
        h->flag = 1;
 
        h = h->next;
    }
 
    return false;
}
 
/* Driver program */
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}