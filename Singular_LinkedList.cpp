#include <iostream>
using namespace std; 


struct node
{
    int data; 
    struct node *next; 
};


struct node *head = NULL; 
struct node *temp; 
int count = 0;
int pos; 
int length; 



//CREATING A LINKED LIST AND INSERTING ELEMENTS IN IT 

void implementation(){
node *newnode = new node; 
int choice; 
while(choice){

node *newnode = new node; 
cout << "enter data" <<endl;
cin >> newnode -> data; 
newnode -> next = NULL; 


if(head==0){
    head = temp = newnode;
}
else {
    temp -> next = newnode; 
    temp = newnode; 

}

cout << "do u want to continue? " <<endl; 
cin >> choice; 

   }

}


//INSERTION AT BEGINING. 
void ins_beg(){
cout << "LET'S SEE INSERTION AT BEGINING:- " <<endl;
node *newnode = new node; 
cout << "enter the data that u want to insert at begining" <<endl; 
cin >> newnode -> data; 

if(head == NULL){
    head = newnode; 
}
else {
newnode -> next = head; 
head = newnode;
}

}


//INSERTION AT END 
void ins_end(){
cout << "LET'S SEE INSERTION AT END:- " <<endl;
cout << "enter the data that u want to insert at end" <<endl; 
node *newnode = new node; 
cin >> newnode -> data; 

newnode -> next = NULL; 

if(head == NULL){
    head = newnode; 
}
else {
temp = head; 
while(temp -> next!= NULL){ // to bring / shift temp till end
    temp = temp -> next; 

}

temp -> next  = newnode; 


cout << " your new linked list is: " <<endl; 

  }

}


//INSERTION AT SPECIFC POSITION 

void ins_spec_pos(){
cout << "enter the position u want to enter" <<endl; 
cin >> pos; 
if(pos > length){
    cout << "invalid posiitoon" <<endl; 

}
else {
    int i = 1; 
    temp = head; 
    while(i < pos){
        temp = temp -> next; 
        i++; 

    }

    node *newnode = new node; 

    cout << "enter the data u want to insert" <<endl; 
    cin >> newnode -> data ; 

    cout <<" your new linked list is: " <<endl; 

    newnode ->next = temp -> next; 
    temp ->next = newnode; 

  }

}

//SINGULAR LINKED LIST 

//DELETE FROM BEGINING 
void del_beg(){
temp = head; 
if(head==NULL){
    cout << "empty list" <<endl; 
}
else{

cout << " your new linked list is: " <<endl; 
head = head->next; 
delete temp; 
}
}



//DELETE FROM END
void del_end(){
struct node *prevnode; 
temp = head; 
while(temp -> next != NULL){
    prevnode = temp; 
    temp = temp -> next; 

}
if(temp == head){
    
     head =0; 
        
}   
else {

cout << " your new linked list is: " <<endl; 
    prevnode -> next = 0; 
    
}

delete temp;

}



//DELETE FROM SPECIFIC POSITION 
void del_spec_pos(){
struct node *nextnode; 

cout << "enter posiiton" <<endl; 
cin >> pos; 
int i = 1; 
temp = head; 
while(i<pos-1){
    temp = temp -> next; 
    i++; 

}
cout << " your new linked list is: " <<endl; 
nextnode = temp->next; 
temp -> next = nextnode -> next;
delete nextnode; 

}


//DISPLAYING THE LINKED LIST 

void display(struct node *temp, struct node *head){
    cout << "here is your linked list:- " <<endl; 
    int count = 0; 
  
  temp = head; 
  while(temp!= NULL){
        cout << temp-> data << " ";  
        temp = temp -> next; 
        count ++; 
    }
    cout << endl; 
 length = count; 
    cout << "total no. of elements are: " << count << endl; 

}



// TO KNOW THE LENGTH OF THE LINKED LIST 

void getlength(){
    int count = 0; 
    temp = head; 
    while(temp !=NULL){
        cout << temp -> data << endl;
        temp = temp-> next; 
        count ++; 
    }

    cout << "length is: " << count << endl; 
}



// REVERSE A LINKED LIST 


void reverse(){

    struct node *prevnode; 
    struct node *currentnode; 
    struct node *nextnode; 

    prevnode = 0; 
    currentnode = nextnode = head; 
    while(nextnode != NULL){
        nextnode = nextnode -> next; 
        currentnode -> next = prevnode; 
        prevnode = currentnode; 
        currentnode = nextnode; 

    }

    head = prevnode; 
    
}



int main(){
    implementation(); 
    display(temp, head);
    ins_beg();
    display(temp, head);
     ins_beg();
    display(temp, head);
     ins_beg();
    display(temp, head);
    ins_spec_pos();
    display(temp, head);
    ins_end();
    display(temp, head);
    del_beg();
    display(temp, head);
    del_end();
    display(temp, head);
    del_spec_pos();
    display(temp, head);
    getlength(); 
    reverse();
    display(temp, head);
    


    return 0; 
    
}       
