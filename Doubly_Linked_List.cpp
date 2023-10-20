#include <iostream> 
using namespace std; 

struct node 
{
    int data; 
    struct node *next; 
    struct node *prev;
    
}; 

struct node *head = NULL; 
struct node *temp; 
struct node *tail;
struct node *current; 
struct node *nextnode; 
int count = 0;
int pos; 
int length; 



//IMPLEMENTING

void implement(){

    int choice; 
 
    while(choice){

        node *newnode = new node; 
        cout << "enter the data u want to add: " << endl; 
        cin >> newnode -> data; 
        newnode -> next = 0; 
        newnode -> prev = 0; 

        if(head == NULL){
            head = temp = tail = newnode; 

        }else {
            temp -> next = newnode; 
            newnode -> prev = temp; 
            temp = newnode; 
            tail = temp; 
        }

        cout << "do u want to continue" <<endl; 
        cin >> choice; 

    }
   
    
}



//INSERTION AT BEGINING 

void ins_at_beg(){
    node *newnode = new node; 
    cout << "enter the data u want to insert at begining:  " <<endl; 
    cin >> newnode -> data ;

    newnode -> next = head; 
    head -> prev = newnode; 
    head = newnode; 

}



//INSERTION AT END 

void ins_at_end(){
    node *newnode = new node; 
    cout << "enter the data u want to insert at end:  " <<endl; 
    cin >> newnode -> data ;
    if(head == 0){
        head = tail = newnode; 

    }
    else {
   
        tail -> next = newnode; 
        newnode -> prev = tail; 
        tail = newnode; 

    }
   
}



//INSERTION AT A POSITION

void ins_at_pos(){
    

    node *newnode = new node; 
    cout << "enter the position u want to insert in: " <<endl; 
    cin >> pos; 

    cout << "enter the data u want to insert at that position: " <<endl; 
    cin >> newnode -> data; 

    if(pos>length){
        cout << "invalid posiiton" <<endl; 
    }
    else if(pos==1){
        ins_at_beg(); 
    }
    
    else {
        int i = 1; 
        temp = head; 
         while(i < pos-1){
        temp = temp -> next; 
        i++; 

        }
        newnode -> prev = temp; 
        newnode -> next = temp -> next; 
        temp -> next = newnode; 
        newnode -> next -> prev = newnode;  

    }

}



//INSERTION AFTER A POSITION 

void ins_after_pos(){
    

    node *newnode = new node; 
    cout << "enter the position after which u want to insert in: " <<endl; 
    cin >> pos; 

    cout << "enter the data u want to insert at that position: " <<endl; 
    cin >> newnode -> data; 

    if(pos>length){
        cout << "invalid posiiton" <<endl; 
    }
    else if(pos == 1){
        ins_at_beg(); 
    }
    
    else {
        int i = 1; 
        temp = head; 
         while(i < pos){
        temp = temp -> next; 
        i++; 

        }
        newnode -> prev = temp; 
        newnode -> next = temp -> next; 
        temp -> next = newnode; 
        newnode -> next -> prev = newnode;  

    }


}


//DELETION FROM BEGINING 

void del_beg(){
    if(head == NULL){
        cout << "list is empty: " <<endl; 

    }
    else {

        head = head -> next; 
        head -> prev = NULL; 
        delete temp; 
    }
}



//DELETION FROM END

void del_end(){
    if(head == NULL){
        cout << "list is empty" <<endl; 
    }
    else {
        temp = tail; 
        tail = tail->prev; 
        tail -> next = NULL; 
        delete temp; 
    }
}


//DELETION FROM A POSITION

void del_pos(){

    cout << "enter the position that you want to delete from: " <<endl; 
    cin >> pos; 

    if(head==NULL){
        cout << "list empty: " <<endl; 
    }
    else if(pos > length){
        cout << "invalid position" <<endl;
    }
    {   temp = head; 
        int i = 1; 
        while(i < pos){
            temp = temp->next; 
            i++;
        }

        temp -> prev -> next = temp -> next; 
        temp -> next -> prev = temp -> prev; 
        delete temp; 
    }
}


//REVERSE 

void reverse(){
    if(head == NULL){
        cout << "empty list" <<endl; 
    }
    else{
        current = head;
        while(current!=0){
            nextnode =  current -> next; 
            current -> next = current -> prev; 
            current -> prev = nextnode; 
            current = nextnode; 
        }

        current = head; 
        head = tail; 
        tail = current; 

    }


}


void display(struct node *temp, struct node *head){
    cout << "here is your linked list: " << endl; 
    int count = 0; 
    temp = head; 
    while(temp!=NULL){

        cout << temp -> data << " " ;
        temp = temp-> next;
        count++ ; 
        length = count; 

    }
    cout << endl; 

    cout << "tot. no. of elements in the list now: " << count << endl; 

    cout << endl; 
    
}

//SAMPLE CASES

int main(){

    implement();
    display(temp, head);

    ins_at_beg();
    display(temp, head);

    ins_at_end();
    display(temp, head);

    ins_at_pos();
    display(temp, head);

    ins_after_pos();
    display(temp, head);

    del_beg();
    display(temp, head);

    del_end();
    display(temp, head);
    
    del_pos();
    display(temp, head);

    reverse();
     display(temp, head);



}
