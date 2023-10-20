#include <iostream>
using namespace std; 

struct node
{
    int data; 
    struct node *next; 

};

struct node *temp; 
struct node *head = NULL; 
struct node *tail; 
struct node *current; 
struct node *prev;
struct node *nextnode; 
int count; 
int choice; 
int length;
int pos; 

//IMPLEMENTING

void implement(){
int choice; 

node *newnode = new node; 
while(choice){
cout << "enter the data: "<<endl; 
cin >> newnode -> data; 
newnode ->next = 0; 

if(head ==0){
    head = temp = newnode; 
}
else {
    temp -> next = newnode; 
    temp = newnode; 
}

temp -> next = head; 
cout << "do u want to continue? " <<endl; 
cin >> choice; 

}

cout <<endl; 
}

void implement_by_tail(){
int choice; 

node *newnode = new node; 
while(choice){
cout << "enter the data: "<<endl; 
cin >> newnode -> data; 
newnode ->next = 0; 
if(head == 0){
    head = tail = newnode; 

}
else{
    tail -> next = newnode; 
    tail = newnode; 
}
tail -> next = head; 
cout << " do u want to continue? " <<endl; 
cin >> choice; 

}
cout << endl; 
}




//INSERTION AT BEGINING 

void ins_at_beg(){
    node *newnode = new node; 
    cout << "enter the data u want to insert at begining:  " <<endl; 
    cin >> newnode -> data ;

    newnode -> next = 0; 

    if(tail==0){
    tail = newnode; 
    tail-> next = newnode; 

   }
   else {
    newnode -> next = tail -> next; 
    tail->next = newnode; 

   }
}




//INSERTION AT END 

void ins_at_end(){
    node *newnode = new node; 
    cout << "enter the data u want to insert at end:  " <<endl; 
    cin >> newnode -> data ;
    if(tail==0){
        tail = newnode; 
        tail -> next = newnode; 

    }
    else{
        newnode -> next = tail -> next; 
        tail -> next = newnode; 
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

    if(pos<0 || pos > length){
        cout << "invalid posiiton" <<endl; 
    }
    else if(pos==1){
        ins_at_beg(); 
    }
    
    else {
        int i = 1; 
        temp = tail->next;  
         while(i < pos-1){
        temp = temp -> next; 
        i++; 

        }

        newnode -> next = temp-> next; 
        temp -> next = newnode;
    }

}


//DISPLAYING  WITH THE HELP OF HEAD 

void display(struct node *temp, struct node *head){
    cout << "here is your linked list: " << endl; 
    int count = 0; 
    int length;
    temp = head; 
    while(temp->next != head){

        cout << temp -> data << " "; 
        temp = temp-> next; 
    }

    cout << temp-> data << endl; 
    count++; 
    length = choice; 

}


//DISPLAY WITH THE HELP OF TAIL ONLY 

void display_by_tail(struct node *temp, struct node *tail){
    cout << " here is your linked list: " <<endl; 
    int count = 0; 
    int length; 
    if(tail==0){
        cout << "list is empty" <<endl; 
    }
    else{
        temp = tail -> next;
        while(temp->next!= tail->next){
        cout << temp -> data << " ";
        temp = temp-> next; 
        count++; 
        length = count;
        
    }
  }
}



//DELETION FROM BEGINING 

void del_beg(){
    if(tail== NULL){
        cout << "list is empty: " <<endl; 

    }
    else if(temp == tail){
        tail = 0; 
        delete temp; 
    }
    else  {
        tail -> next = temp-> next; 
        delete temp; 

    }
}



//DELETION FROM END


void del_end(){
   
struct node *prev;
    if(head == NULL){
        cout << "list is empty" <<endl; 
    }
    else if (current -> next = current){
        tail = 0; 
        delete current; 
    }
    else {
        while(current -> next != tail->next){
            prev = current; 
            current = current -> next; 
        }
        prev -> next = tail -> next; 
        tail = prev; 
        delete current; 

    }
}




//DELETION FROM A POSITION

void del_pos(){

    cout << "enter the position that you want to delete from: " <<endl; 
    cin >> pos; 
    current = tail-> next; 

    if(pos <1 || pos>length){
        cout << "invalid " <<endl; 
    }
    else if(pos ==1 ){
       del_beg();
    }
    else{
        int i = 1; 
        while(i < pos-1){
            current = current->next; 
            i++;
        }

        nextnode = current -> next; 
        current -> next  = nextnode -> next; 
        delete nextnode; 
    }
}



//REVERSE 


void reverse(){
    struct node * prev;
    current = tail -> next; 
    if(tail == NULL){
        cout << "empty list" <<endl; 
    }
    else{
        
        while(current!=tail){
            prev = current; 
            current = nextnode; 
            nextnode = current -> next; 
            current -> next = prev; 
            
        }

       nextnode -> next = tail; 
       tail = nextnode; 

    }


}


int main(){
    implement();
    display(temp, head);
    implement_by_tail();
    display_by_tail(temp, tail); 
    ins_at_beg();
    display_by_tail(temp, tail); 
    ins_at_end();
    display_by_tail(temp, tail); 
    ins_at_pos();
    display_by_tail(temp, tail); 
    del_beg();
    display_by_tail(temp, tail); 
    del_end();
    display_by_tail(temp, tail); 
    del_pos();
    display_by_tail(temp, tail); 
    reverse(); 
    display_by_tail(temp, tail); 

}
