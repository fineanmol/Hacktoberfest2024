

// Singly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node(){
        int value = this -> data;
        //memory free
        if(this->next != nullptr){
            delete next;
            this -> next = nullptr;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void InsertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &head, int d) {
    Node* newNode = new Node(d);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertAtPosition(Node* &head, int position, int d) {
    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }

    if (position <= 0) {
        cout << "Invalid position. Position should be greater than 0." << endl;
        return;
    }

    Node* temp = head;
    int cnt = 1;



    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) {
        cout << "Position exceeds the length of the list. Element not inserted." << endl;
        return;
    }

    Node* nodetoinsert = new Node(d);

    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

//Deletion
void deleteNode(int position, Node* &head){
    if(position == 1){
        head = head -> next;
        Node* temp = head;
        temp -> next = nullptr;
        delete temp;
    }

    else
    {
        Node* curr = head;
        Node* prev = nullptr;

        int cnt = 1;
        while(cnt <= position){
            prev = curr;
            curr=curr->next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = nullptr;
        delete curr;
    }
    
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

Node* sortedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // List is empty or has only one element, so it's already sorted.
        return head;
    }

    Node* sortedList = nullptr; // Initialize the sorted list as empty.
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        if (sortedList == nullptr || current->data <= sortedList->data) {
            // Insert at the beginning of the sorted list.
            current->next = sortedList;
            sortedList = current;
        } else {
            // Traverse the sorted list to find the insertion point.
            Node* temp = sortedList;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            // Insert the current node after temp.
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }

    return sortedList; // Return the head of the sorted list.
}



// ListNode* sortList(ListNode* head) {

//         if (!head || !head->next)
//             return head;
        
//         ListNode* mid = findMiddle(head);
//         ListNode* left = sortList(head);
//         ListNode* right = sortList(mid);
        
//         return merge(left, right);
//     }
    
//     ListNode* findMiddle(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
        
//         while (fast->next && fast->next->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         ListNode* mid = slow->next;
//         slow->next = nullptr; // Split the list into two halves
//         return mid;
//     }
    
//     ListNode* merge(ListNode* left, ListNode* right) {
//         ListNode dummy(0);
//         ListNode* current = &dummy;
        
//         while (left && right) {
//             if (left->val < right->val) {
//                 current->next = left;
//                 left = left->next;
//             } else {
//                 current->next = right;
//                 right = right->next;
//             }
//             current = current->next;
//         }
        
//         if (left)
//             current->next = left;
//         else if (right)
//             current->next = right;
        
//         return dummy.next;
        
//     }


//Traverse
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main() {
    Node* node1 = new Node(10);
    cout << "Node 1 Data: " << node1->data << endl;
    cout << "Node 1 Next: " << node1->next << endl;

    Node* head = node1;
    print(head);

    InsertAtHead(head, 12);
    print(head);

    InsertAtTail(head, 15);
    print(head);

    InsertAtPosition(head, 2, 56);
    print(head);

    deleteNode(2, head);
    print(head);

    sortedList(head);
    print(head);



    cout << "Head: " << head->data << endl;

    // Find the tail of the linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    cout << "Tail: " << tail->data << endl;


    head = reverseLinkedList(head);
    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}


// Singly linked list