
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void Print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void Insert(struct Node** head, int newdata, struct Node** tail){
    struct Node *newNode = new Node(newdata);    
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    else{
        struct Node *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        *tail = newNode;
    }
}

struct Node* sortedMerge(struct Node* head1, struct Node* head2){
    struct Node *temp, *head;
    int flag = 0;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(flag == 0){
                head = head1;
                temp = head;
            }
            else{
                temp->next = head1;
                temp = temp->next;
            }
            head1 = head1->next;
        }
        else{
            if(flag == 0){
                head = head2;
                temp = head;
            }
            else{
                temp->next = head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }
        flag = 1;
    }
    while(head1 != NULL ){
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }
    while(head2 != NULL ){
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }
    return head;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        int n1,n2,x;

        cin>>n1>>n2;
        for(int i=0;i<n1;i++){
            cin>>x;
            Insert(&head1,x,&tail1);
        }
        for(int i=0;i<n2;i++){
            cin>>x;
            Insert(&head2,x,&tail2);
        }
        
        struct Node* head = sortedMerge(head1, head2);
        Print(head);
    }
    return 0;

}