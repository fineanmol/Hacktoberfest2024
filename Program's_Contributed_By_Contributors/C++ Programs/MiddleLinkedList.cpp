#include <iostream>
#include <string>
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

void Insert(struct Node* (*head), int newdata){
    struct Node* newNode = new Node(newdata);    
    if(*head == NULL)
        *head = newNode;
    else{
        struct Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int getMiddle(struct Node** head){
    struct Node *temp = *head;
    struct Node *mid = *head;
    int count=0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    count = (count/2) + 1;
    while(count > 1){
        mid = mid->next;
        count--;
    }
    return mid->data;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node* head = NULL;
        int N,l,out;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>l;
            Insert(&head,l);
        }
        // Print(&head);
        out = getMiddle(&head);
        cout<<out<<endl;
	}
	return 0;

}